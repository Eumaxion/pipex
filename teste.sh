#!/bin/bash


verde="\033[0;32m"
vermelho="\033[0;31m"
amarelo="\033[1;33m"
reset="\033[0m"

PIPEX=./pipex

echo "conteúdo" > temp1.tmp
in_text="temp1.tmp"
out_text="out.tmp"

teste() {
	a1="wc -l"
	a3="grep a"

	$PIPEX "$a1" "$a3" $out_text
	teste_3arg=$?
	echo -e "${amarelo}teste com menos de 4 arg:${reset}"
	if [ "$teste_3arg" -eq 1 ]; then
		echo -e "${verde} sucesso ${reset}"
	else
		echo -e "${vermelho} error ${reset}"
	fi

	echo -e "${amarelo}teste com um arg vazio:${reset}"
	$PIPEX $in_text "$a1" "" $out_text
	teste_empty=$?
	if [ "$teste_empty" -eq 1 ]; then
		echo -e "${verde} sucesso ${reset}"
	else
		echo -e "${vermelho} error ${reset}"
	fi

	echo -e "${amarelo}teste com arquivo sem permissão:${reset}"
	chmod 000 "$in_text"
	chmod 000 "$out_text"
	teste_no_p1=$($PIPEX $in_text "$a1" "$a3" $out_text)
	teste_no_p2=$($PIPEX $in_text "$a1" "$a3" $out_text)
	if echo "$teste_no_p1" | grep -q "Permission denied" || echo "$teste_no_p2" | grep -q "Permission denied" ; then
		echo -e "${verde} sucesso ${reset}"
	else
		echo -e "${vermelho} error ${reset}"
	fi
}
teste

rm -f $in_text $out_text
