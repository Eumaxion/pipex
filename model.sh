#!/bin/bash
# -----------------------------------------
# Script de testes automáticos para push_swap
# -----------------------------------------

# Cores para deixar a saída mais legível
verde="\033[0;32m"
vermelho="\033[0;31m"
amarelo="\033[1;33m"
reset="\033[0m"

# Contadores para estatísticas no final
total=0
passou=0
falhou=0

# Função para rodar um teste
# Parâmetros:
#   1 = lista de números para testar
#   2 = número máximo de movimentos permitidos (opcional)
teste() {
    lista="$1"
    max_moves=$2
    total=$((total + 1))

    # Executa push_swap e captura saída
    saida=$(./push_swap $lista)

    # Conta quantas linhas (movimentos) a saída tem
    moves=$(echo "$saida" | wc -l)

    # Roda o checker para verificar se a saída está correta
    resultado=$(echo "$saida" | ./checker $lista)

    # Verifica se o resultado é "OK"
    if [ "$resultado" = "OK" ]; then
        if [ -n "$max_moves" ] && [ "$moves" -gt "$max_moves" ]; then
            echo -e "${amarelo}⚠️  Teste $total: Correto, mas passou do limite ($moves movimentos)${reset}"
        else
            echo -e "${verde}✅ Teste $total: OK ($moves movimentos)${reset}"
            passou=$((passou + 1))
        fi
    else
        echo -e "${vermelho}❌ Teste $total: Falhou ($resultado)${reset}"
        falhou=$((falhou + 1))
    fi
}

# -----------------------------------------
# Casos de teste fixos
# -----------------------------------------
teste "2 1"
teste "3 2 1"
teste "1 5 2 4 3"

# -----------------------------------------
# Casos aleatórios
# -----------------------------------------
for i in {1..5}; do
    lista=$(seq 1 5 | shuf) # gera números 1..5 embaralhados
    teste "$lista" 12       # define limite de 12 movimentos
done

# -----------------------------------------
# Relatório final
# -----------------------------------------
echo -e "\n${amarelo}Resumo:${reset}"
echo -e " Total: $total"
echo -e " Passou: ${verde}$passou${reset}"
echo -e " Falhou: ${vermelho}$falhou${reset}"
