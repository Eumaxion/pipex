#!/bin/bash


verde="\033[0;32m"
vermelho="\033[0;31m"
amarelo="\033[1;33m"
reset="\033[0m"

echo "conteúdo" > temp1.tmp
in_text="temp1.tmp"
out_text="out.tmp"

teste() {
	a1="wc -l"
	a3="grep a"

	teste_3arg=$(./pipex "$a1" "$a3" $out_text)
	if [ "$teste_3arg" = "ERROR" ]; then
		echo -e "${verde} sucesso ${reset}"
	else
		echo -e "${vermelho} error ${reset}"
	fi

	teste_empty=$(./pipex $in_text "$a1" "" $out_text)
	if [ "$teste_empty" = "" ]; then
		echo -e "${verde} sucesso ${reset}"
	else
		echo -e "${vermelho} error ${reset}"
	fi

	chmod 000 "$in_text"
	teste_no_p=$(./pipex $in_text "$a1" "$a3" $out_text)
	if echo "$teste_no_p" | grep -q "Permission denied" ; then
		echo -e "${verde} sucesso ${reset}"
	else
		echo -e "${vermelho} error ${reset}"
	fi

	echo "${teste_3arg}"
	echo "${teste_empty}"
	echo "${teste_no_p}"
}
teste

rm -f $in_text $out_text
