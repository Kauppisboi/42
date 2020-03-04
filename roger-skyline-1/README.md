#Debian Installation
1. Install Debian 10.3 on Oracle VB
2. Create one partition to have 4.2 GB (which actually means you need to allocate 4.5 GB)
3. Install SSH server and System utilities only

#Update OS Packages
1. Install sudo command: apt install sudo
2. Package update: sudo apt update
3. Install newest versions of packages: sudo apt upgrade

#Check partition amount with sudo privilages
sudo fdisk -l

#Create Non-Root User
1. Create new user: sudo adduser <login>
2. Give root privileges sudo adduser <login> sudo OR sudo usermod -aG sudo <login>

#Configure Static IP
1. Set NAT -> Bridged Adapter in your VM settings (Network)
2. Edit file /etc/network/interfaces and setup your network:

# The primary network interface
auto enp0s3

3. Create file enp0s3 file in interfaces.d:
iface enp0s3 inet static
	  address 10.12.180.126
	  netmask 255.255.255.252
	  gateway 10.12.254.254

#Change the SSH Default Port
1. Modify /etc/ssh/sshd_config file:
2. Choose a port number, for example 50111, and just write in the file Port 50111
3. Then restart using SSH: sudo /etc/init.d/ssh restart
4. Check that connection worked: ssh admin@10.12.10.126 -p 50111

#Setting Up PublicKeys
1. Create a publickey: ssh-keygen -t rsa
2. Give your public key to the server: ssh-copy-id admin@10.12.10.126 -p 50111
3. Modify file /etc/ssh/sshd_config to remove root login permit and password authentication:
# PermitRootLogin yes --> PermitRootLogin no
# PasswordAuthentication yes --> PasswordAuthentication no
4. Then restart service:
sudo service sshd sshd restart
sudo service ssh status 
5. Try again to connect yourself into server with just publickeys

#Firewall Setup
1. Install ufw package: sudo apt install ufw
2. Set following rules:

sudo ufw default deny incoming
sudo ufw default allow outgoing
sudo ufw allow https #OR sudo ufw allow 443
sudo ufw allow 80/tcp
sudo ufw allow 50111/tcp

3. Enable UFW, using command:

sudo ufw enable

4. Check which rules are set:

sudo ufw status verbose

#DOS (Denial of Sevice Attack)
1. Install fail2ban package
sudo apt install fail2ban
2. Copy file /etc/fail2ban/jail.config -> /etc/fail2ban/jail.local
- jail.local file preserves all the info that jail.config consisted if it is modified
3. Write these commands into jail.local file:
[DEFAULT]

bantime = 10m
findtime = 10m
maxretry = 5

[sshd]
enabled = true
port = 50111
filter = sshd
maxretry = 2
findtime = 60m
bantime = 10m
logpath = %/(sshd_log)s
backend = %(sshd_backend)s

[portscan]
enabled = true
filter = portscan
logpath = /var/log/syslog/
maxretry = 1
findtime = 5m
bantime = 10m

[http-get-dos]
enabled = true
filter = http-get-dos
logpath = /var/log/apache2/access.log
maxretry = 15
findtime = 5m
bantime = 10m
action = iptables[name=HTTP, port=http, protocol=tcp]

4. Create 2 files: /etc/fail2ban/filter.d/http-get-dos.conf and /etc/fail2ban/filter.d/portscan.conf
- add text to http-get-dos.conf:
[Definition]
failregex = ^<HOST> -.*"(GET|POST).*
ignoreregex =

- add text to portscan.conf:
[Definition]
failregex = UFW BLOCK.* SRC=<HOST>
ignoreregex =

5. Restart service:
sudo ufw reload && sudo service fail2ban restart

6. Activate fail2ban:
sudo systemctl enable fail2ban

7. Check fail2ban status:
sudo systemctl status systemctl

8. See rules added by fail2ban:
sudo iptables -L

9. Test with wrong username@rigth_ip_address to log with ssh, then run
sudo fail2ban-client status sshd
# to see total number of banned IPs

#Setting up Protection Against Port Scans

1. sudo apt-get update && sudo apt-get install portsentry

2. Stop service
sudo /etc/init.d/portsentry stop

3. Edit /etc/default/portsentry:
TCP_MODE="atcp"
UDP_MODE="audp"

4. Edit /etc/portsentry/portsentry.conf:
BLOCK_UDP="1"
BLOCK_TCP="1"

5. Uncomment in file /etc/portsentry/portsentry.conf
KILL_ROUTE="/sbin/iptables -I INPUT -s $TARGET$ -j DROP"

6. Restart service
sudo /etc/init.d/portsentry start

7. TESTING
Use another VM (with different IP address) to scan your ports using
nmap 10.12.180.126
->Then use your own VM to see whether portscan was reported. Use:
sudo fail2ban-client status portscan

#Disable Services That Won't Be Needed

1. List all the services:
sudo service --status-all

2. There's nothing extra services available right now so you don't need. However, you could disable services using:
sudo systemctl disable SERVICE_NAME

