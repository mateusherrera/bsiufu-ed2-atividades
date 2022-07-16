# Atividades - ED2

Atividades realizadas na disciplina de Estrutura de Dados II (ED2).

## Para compilar com gcc no terminal do Linux

Com o terminal, vá a pasta em que está o código fonte, e rode o seguinte comando:

```
gcc -c nome-do-arquivo.c
```

E depois gerar o executável:

```
gcc -o nome-do-executavel nome-do-objeto.o
```

## Opcional: Organizar '.o' e executável

Na pasta da compilação.

Crie os diretórios 'obj/', para o '.o', e bin/, para o executável:

```
mkdir obj/
mkdir bin/
```

Depois mova o arquivo objeto e o executável para suas pastas:

```
mv *.o obj/
mv nome-do-executavel bin/
```

## Para rodar o executável no terminal

Digite o comando na pasta onde está o executável:

```
./nome-do-executavel
```
