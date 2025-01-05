# qsql

(Pronunciado como **keskel**)

Uma biblioteca para criar e gerir bancos de dados relacionais focada na experiência do programador.

Fortemente inspirada por [Lapis](https://leafo.net/lapis)

[Read in English](README.md)

# Metas

- Fornecer uma forma uniforme para trabalhar com os diversos bancos de dados relacionais
- Permitir fácil integração de bancos de dados com linguagens de programação

# Por que?

Trabalhar com bancos de dados, especialmente os relacionais, geralmente gera uma dependência estrutural forçando o programador a modificar de forma conjunta, o código da aplicação e do banco de dados.

qsql tenta reduzir ao máximo esta dependência.

# Como?

Podemos resumir em 1 palavra:

### Simplicidade

Consultas são geradas com base em métodos simples e práticos, reduzindo drasticamente o tempo de desenvolvimento.

```C++

for(auto usuario : Usuario.find_all()){
    cout << user["primeiroNome"] << std::endl;
}

Usuario.update(1,{ "primeiroNome", "João" });

```

# Suporte

## Bancos de dados

| Nome       | Suportado  |
|------------|------------|
| PostgreSQL | Sim        |
| Sqlite3    | Sim        |
| Duckdb     | Brevemente |
| MySQL      | Brevemente |

# Instalando em C++

qsql está disponível para C++ como uma biblioteca apenas de cabeçalho.

## Com CMake

1. Mova o diretório `qsql` para o diretório do seu projeto.
2. Adicione `include_directories(./qsql)`.
3. Faça o link com as blibliotecas necessárias (libpqxx para postgres ou SQLitepp)

## Instalando globalmente

Mova o diretório `qsql` para o diretório de inclusão do seu compilador.
