# qsql

(Pronounced as **keskel**)

A library for creating and managing relational databases focused on the developer experience.

Heavily inspired by [Lapis](https://leafo.net/lapis)

[Ver em português](README.pt.md)

# **Goals**

- Provide a uniform way to work with the various types of relational databases
- Allow easy database integration with programming languages

# **Why?**

Working with especially relational databases, usually creates a structural dependency forcing the developer to modify the application and database code together.

qsql tries to reduce this dependency to the maximum.

# **How?**

We can summarize in one word:

### **Simplicity**

Queries are generated based on simple and practical methods, drastically reducing development time.

```C++

for(auto user : User.findAll()){
    cout << user["firstName"] << std::endl;
}

User.update(1,{ "firstName", "John Doe" });

```

# **Support**

## **Languages**

| Name       | Supported |
| ---------- | --------- |
| Cpp        | Yes       |
| Go         | Soon      |
| Rust       | Soon      |
| JavaScript | Soon      |
| Java       | Soon      |

## **Databases**

| Name       | Supported |
| ---------- | --------- |
| PostgreSQL | Yes       |
| MariaDB    | Soon      |
| MySQL      | Soon      |

# Setting up in Cpp

qsql is available for cpp has a header only library.

## With CMake
1. move the directory `qsql` to your projects directory
2. add `include_directories(./qsql)`

## Installing globally
move the directory `qsql` to your compiler's include directory.