#!/bin/bash

# Cores
verde="\033[1;32m"
vermelho="\033[1;31m"
amarelo="\033[1;33m"
reset="\033[0m"

PIPEX=./pipex   # Caminho para o seu executável

# Função para executar teste
run_test() {
    descricao=$1
    shift
    cmd="$@"

    echo -ne "${amarelo}$descricao:${reset} "
    $cmd >/dev/null 2>&1
    ret=$?
    if [ $ret -ne 0 ]; then
        echo -e "${verde}[OK]${reset}"
    else
        echo -e "${vermelho}[FAIL]${reset} (ret=$ret)"
    fi
}

# Preparação de arquivos
echo "arquivo normal" > in.txt
echo "out file" > out.txt

# Testes
run_test "1. Arquivo de entrada inexistente" \
    $PIPEX nofile.txt "ls" "wc" out.txt

chmod 000 in.txt
run_test "2. Arquivo de entrada sem permissão" \
    $PIPEX in.txt "ls" "wc" out.txt
chmod 644 in.txt

chmod 444 out.txt
run_test "3. Arquivo de saída sem permissão" \
    $PIPEX in.txt "ls" "wc" out.txt
chmod 644 out.txt

run_test "4. Comando inexistente" \
    $PIPEX in.txt "comando_que_nao_existe" "wc" out.txt

echo "echo teste" > script.sh && chmod 000 script.sh
run_test "5. Sem permissão de execução" \
    $PIPEX in.txt "./script.sh" "wc" out.txt
chmod 755 script.sh

run_test "6. Argumentos insuficientes" \
    $PIPEX in.txt "ls"

run_test "7. Argumento inválido no comando" \
    $PIPEX in.txt "ls --opcao_invalida" "wc" out.txt

run_test "8. PATH vazio" \
    env PATH="" $PIPEX in.txt "ls" "wc" out.txt

run_test "9. PATH errado" \
    env PATH="/abc" $PIPEX in.txt "ls" "wc" out.txt

mkdir dir_in
run_test "10. Arquivo de entrada é diretório" \
    $PIPEX dir_in "ls" "wc" out.txt
rmdir dir_in

mkdir dir_out
run_test "11. Arquivo de saída é diretório" \
    $PIPEX in.txt "ls" "wc" dir_out
rmdir dir_out

rm -f script.sh in.txt out.txt