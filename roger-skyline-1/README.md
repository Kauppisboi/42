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
2. 