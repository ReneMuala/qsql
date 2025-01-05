---
--- Generated by EmmyLua(https://github.com/EmmyLua)
--- Created by ReneMuala.
--- DateTime: 1/4/2025 14:21
---
add_rules("mode.debug", "mode.release")
add_requires("sqlitecpp", "fmt", "gtest")

if is_plat("windows") then
    add_requires("conan::libpqxx/7.9.2", {alias = "libpqxx", configs = {settings = "compiler.cppstd=17"}})
else
    add_requires("libpqxx")
end

target("qsql-example")
    add_packages("fmt", "libpqxx", "sqlitecpp")
    set_languages("c++23")
    set_kind("binary")
    add_includedirs(".")
    add_files("example/*.cpp")

target("qsql-test")
    add_packages("fmt", "libpqxx", "sqlitecpp", "gtest")
    set_languages("c++23")
    set_kind("binary")
    add_includedirs(".")
    add_files("test/*.cpp")