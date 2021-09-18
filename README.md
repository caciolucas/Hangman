Hangman
# Jogo da forca

## O que é?

O jogo da forca é um jogo de letras, onde o jogador tem que acertar as letras escondidas da palavra selecionada. Nesse jogo, o jogador tem 6 chances para acertar a palavra.

## Regras

- Para cada chute acertada, o jogador recebe 1 PONTO (por cada ocorrência da letra escolhida na palavra)
- Para cada chute errada, o jogador perde 1 PONTO e 1 CHANCE
- Ao acertar uma palavra o jogador ganha 2 PONTOS
- Se acertar a palavra sem erros, o jogador ganha 1 PONTO ADICIONAL

## Como jogar?

O jogador deverá escolher uma letra por rodada e será verificado se a letra está na palavra escolhida. Ao acertar a palavra, o jogador pode escolher se quer jogar novamente ou não. Caso o jogador não queira mais jogar ou caso o jogador perca todas as 6 chances e o boneco seja enforcado, o jogo acaba. Com o fim do jogo, o jogador deve informar seu nome para salvar a sua pontuação.

## Como compilar e executar?

Para compilar e poder jogar, é preciso seguir os seguintes passos:

1.  Criar a pasta onde os arquivos objetos e o arquivo final será armazendo

```sh
mkdir build
```


2. Executar o makefile para compilar o projeto

```sh
make 
```

3. Executar o arquivo executável passando como parâmetro na linha de argumento o arquivo de texto com as palavras a serem jogadas, por exemplo.

```sh
./build/jogo_da_forca data/words.txt
```

## Atenção!
O arquivo de texto das palavras deve possuir uma palavra por linha. Como no exemplo encontrado no arquivo words.txt