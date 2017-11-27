#!/bin/sh

echo "Apagando arquivos remanescentes do repositório..."
rm -rf physicsFrmwk
echo "Baixando versão mais recente da engine de partículas..."
git clone https://github.com/K17K47/physicsFrmwk.git
echo "Compilando..."
mkdir physicsFrmwk/build
cd physicsFrmwk/build
../configure && make
echo "Feito!"

