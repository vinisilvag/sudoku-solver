# Como executar o código

O programa foi desenvolvido na linguagem C++ e compilado pelo compilador G++, da
GNU Compiler Collection. A versão mínima para execução e que foi utilizada durante o desenvolvimento foi a versão 17 da linguagem. Para compilar o codigo, um `Makefile` com as principais ações a serem executadas foi definido. Os dois comandos disponíveis são: `make`, para compilar o código e criar o executável, e `make clean`, para deletar todos os binários gerados pela compilação anterior.

Antes de ser compilado, é preciso se certificar que a pasta `build` exista no diretório, no mesmo nível das pastas `src` e `include`, para que os binários das classes sejam armazenados. Após ser compilado com o comando `make`, o executável `main` estará disponível na pasta raiz e deverá ser utilizado para executar o código através do comando:

```bash
./main <algoritmo> <entrada>
```

onde um algoritmo válido é um dos caracteres "B", "U", "I", "G" e "A" e na entrada as linhas da matriz do estado inicial devem ser informadas separadas por espaço. Um exemplo de execução válida seria:

```bash
make clean
make
./main B 530070000 600195000 098000060 800060003 400803001 700020006 060000280 000419005 000080079
```

A saída esperada é composta por duas linhas, sendo a primeira composta pelo número de estados expandidos e o tempo de execução do algoritmo separados por vírgula e a segunda o estado final da grade completamente preenchida, no mesmo formato em que ela é passada como parâmetro.

Além disso, o _bash script_ que executa os experimentos também está sendo enviado nos arquivos. Para executá-lo é necessário que a pasta `results` exista no diretório, no mesmo nível das pastas `src` e `include`. Tanto essa pasta quanto a pasta `build` serão enviadas vazias no arquivo comprimido com o código e o relatório.

Para que a saída fique no formato adequado para um CSV, recomendo que duas linhas sejam comentadas e que uma linha seja descomentada no final da função `main`, no arquivo `main.cpp`. Assim, com a modificação, o final da função `main` deve passar a ser:

```cpp
int main(int argc, char *argv[])
{
  ...

  // std::cout << expansions << " " << time << "\n";
  // display_solution(solution);

  dump_to_csv(expansions, time);

  return EXIT_SUCCESS;
}
```

Uma vez que tudo esteja correto e o programa tenha sido recompilado, o _script_ de testes pode ser executado com:

```bash
./run.sh
```
