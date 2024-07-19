# Operating-Systems


Abrir 2 terminais.

no 1º terminal:
gcc cliente.c
./a.out

no 2º terminal
gcc servidor.c
./a.out ficheiroOutput.txt


// inicia servir e cliente, deverá aparecer no cliente

Opened FIFO for writing.
Opened FIFO for reading.

e no servidor:

[DEBUG] opened fifo for reading
[DEBUG] opened fifo for writing



A partir daqui poderemos enviar instruçoes pelo cliente.

execute tempo -u "comando args" para instruçoes singulares -> estas sao escritas para o ficheiro de texto definido acima

ou 

execute tempo -p "comando1 args | comando2 args" etc

o tempo é em ms e é meramente indicativo.

exemplo de comandos:

execute 100 -u "ls -l"

e

execute 100 -p "cat ficheiro.txt | grep "cliente" | wc -l" -> devolve o numero de ocorrencias da palavra cliente no ficheiro.txt






