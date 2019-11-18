#!/BIN/SH

ARG=$1
INDEX=0;

echo "|$ARG|"
cd .. && make re
cd tetriminos

if [$ARG == ""]
then
	while [ $INDEX -lt 27 ]
	do
		echo File is: invalid_input$INDEX.txt
		cat invalid_input$INDEX.txt
		echo Output is:
		../fillit invalid_input$INDEX.txt

		echo File is: valid_input$INDEX.txt
		cat valid_input$INDEX.txt
		echo Output is:
		../fillit valid_input$INDEX.txt
		INDEX=`expr $INDEX + 1`
	done
elif [[ $ARG == valid ]]
then
	echo HALOO
	while [ $INDEX -lt 27 ]
	do
		echo File is: valid_input$INDEX.txt
		cat valid_input$INDEX.txt
		echo Output is:
		../fillit valid_input$INDEX.txt
		INDEX=`expr $INDEX + 1`
	done
elif [[ $ARG == invalid ]]
then
	while [ $INDEX -lt 27 ]
	do
		echo File is: invalid_input$INDEX.txt
		cat invalid_input$INDEX.txt
		echo Output is:
		../fillit invalid_input$INDEX.txt
		INDEX=`expr $INDEX + 1`
	done
else
	echo File is: $ARG
	cat $ARG
	echo Output is:
	../fillit $ARG
fi
