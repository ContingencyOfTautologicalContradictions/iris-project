# Iris Project

The Iris Project aims to become the main replacement for C++ and Rust as a systems-programming language.

On-going project, but you can already test the LSP client & server with the following commands

```
cd Build
cmake . && make
cd ../Client
npm i
npm run build
cd ..
```

And then adding the generated iris binary to the PATH environment variable as 'iris', and running the LSP client.