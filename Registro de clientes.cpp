#include <stdlib.h>
#include <string.h>
#include <stdio.h>
  
typedef struct lugar
{
  
char rua[64];
   
char cidade[64];
   
char estado[64];
   
int numero;
 
} endereco;

typedef struct client
{
  
int id;
   
char nome[64];
   
char telefone[32];
   
endereco ender;
 
} cliente;

void
pesquisar_cliente ()
{
  
FILE * arq;
  
arq = fopen ("c:\\nsei\\oi.bin", "rb");
  
if (arq == NULL)
    {
      
printf ("Erro");
      
exit (1);
    
}
  
int n;
  
struct client pessoa;
  
 
n = fread (&pessoa, sizeof (struct client), 1, arq);
  
while (n != 0)
    {
      
printf ("%d - ", pessoa.id);
      
printf ("%s\n", pessoa.nome);
      
printf ("%s", pessoa.ender.rua);
      
printf (", %d\n", pessoa.ender.numero);
      
printf ("%s - ", pessoa.ender.cidade);
      
printf ("%s ", pessoa.ender.estado);
      
printf ("Tel: %s\n", pessoa.telefone);
      
n = fread (&pessoa, sizeof (struct client), 1, arq);
    
} 
fclose (arq);

 
} 
void

gravar_clientes ()
{
  
FILE * arq;
  
arq = fopen ("c:\\nsei\\oi.bin", "ab");
  
if (arq == NULL)
    {
      
printf ("Erro");
      
exit (1);
    
}
  
int i, n;
  
printf ("Quantos clientes ira gravar?\n");
  
scanf ("%i", &n);
  
struct client pessoa[n];
  
for (i = 0; i < n; i++)
    {
      
printf ("Digite um codigo para o cliente:\n");
      
scanf ("%d%*c", &pessoa[i].id);
      
fflush (stdin);
      
printf ("Digite o nome do cliente:\n");
      
scanf (" %[^\n]s%*c", pessoa[i].nome);
      
printf ("Digite o telefone do cliente:\n");
      
scanf (" %[^\n]s%*c", pessoa[i].telefone);
      
printf ("Digite a rua do cliente:\n");
      
scanf (" %[^\n]s%*c", pessoa[i].ender.rua);
      
printf ("Digite a cidade do cliente:\n");
      
scanf (" %[^\n]s%*c", pessoa[i].ender.cidade);
      
printf ("Digite o estado do cliente:\n");
      
scanf (" %[^\n]s%*c", pessoa[i].ender.estado);
      
printf ("Digite o numero da residencia do cliente:\n");
      
scanf ("%d%*c", &pessoa[i].ender.numero);
      
fwrite (&pessoa[i], sizeof (struct client), 1, arq);
    
 
} 
 
 
fclose (arq);

} 
void

limpar ()
{
  
FILE * arq;
  
arq = fopen ("c:\\nsei\\oi.bin", "wb");
  
if (arq == NULL)
    {
      
printf ("Erro");
      
exit (1);
    
}
  
fclose (arq);

}


void
filtrar_clientes ()
{
  
FILE * arq;
  
arq = fopen ("c:\\nsei\\oi.bin", "rb");
  
if (arq == NULL)
    {
      
printf ("Erro");
      
exit (1);
    
}
  
int n, x, l, v = 0;
  
struct client pessoa;
  
printf
    ("Filtrar os clientes por:\n1-Codigo\n2-Nome\n3-Rua\n4-Cidade\n5-Estado\n");
  
scanf ("%i", &l);
  
switch (l)
    {
    
case 1:
      
printf ("Digite o codigo do cliente:\n");
      
scanf ("%i", &x);
      
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
while (n != 0)
	{
	  
if (x == pessoa.id)
	    {
	      
printf ("%d - ", pessoa.id);
	      
printf ("%s\n", pessoa.nome);
	      
printf ("%s", pessoa.ender.rua);
	      
printf (", %d\n", pessoa.ender.numero);
	      
printf ("%s - ", pessoa.ender.cidade);
	      
printf ("%s ", pessoa.ender.estado);
	      
printf ("Tel: %s\n\n", pessoa.telefone);
	      
v++;
	    
}
	  
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
} 
if (v == 0)
	{
	  
printf ("Nenhum cliente encontrado.\n");
	
}
      
fclose (arq);
      
break;
    
 
case 2:
      
char name[64];
      
fflush (stdin);
      
printf ("Digite o nome do cliente:\n");
      
scanf (" %[^\n]s", name);
      
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
while (n != 0)
	{
	  
if (strcmp (name, pessoa.nome) == 0)
	    {
	      
printf ("%d - ", pessoa.id);
	      
printf ("%s\n", pessoa.nome);
	      
printf ("%s", pessoa.ender.rua);
	      
printf (", %d\n", pessoa.ender.numero);
	      
printf ("%s - ", pessoa.ender.cidade);
	      
printf ("%s ", pessoa.ender.estado);
	      
printf ("Tel: %s\n\n", pessoa.telefone);
	      
v++;
	    
}
	  
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
} 
if (v == 0)
	{
	  
printf ("Nenhum cliente encontrado.\n");
	
}
      
fclose (arq);
      
break;
    
case 3:
      
char street[64];
      
fflush (stdin);
      
printf ("Digite a rua do cliente:\n");
      
scanf (" %[^\n]s", street);
      
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
while (n != 0)
	{
	  
if (strcmp (street, pessoa.ender.rua) == 0)
	    {
	      
printf ("%d - ", pessoa.id);
	      
printf ("%s\n", pessoa.nome);
	      
printf ("%s", pessoa.ender.rua);
	      
printf (", %d\n", pessoa.ender.numero);
	      
printf ("%s - ", pessoa.ender.cidade);
	      
printf ("%s ", pessoa.ender.estado);
	      
printf ("Tel: %s\n\n", pessoa.telefone);
	      
v++;
	    
}
	  
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
} 
if (v == 0)
	{
	  
printf ("Nenhum cliente encontrado.\n");
	
}
      
fclose (arq);
      
break;
    
case 4:
      
char city[64];
      
fflush (stdin);
      
printf ("Digite a cidade do cliente:\n");
      
scanf (" %[^\n]s", city);
      
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
while (n != 0)
	{
	  
if (strcmp (city, pessoa.ender.cidade) == 0)
	    {
	      
printf ("%d - ", pessoa.id);
	      
printf ("%s\n", pessoa.nome);
	      
printf ("%s", pessoa.ender.rua);
	      
printf (", %d\n", pessoa.ender.numero);
	      
printf ("%s - ", pessoa.ender.cidade);
	      
printf ("%s ", pessoa.ender.estado);
	      
printf ("Tel: %s\n\n", pessoa.telefone);
	      
v++;
	    
}
	  
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
} 
if (v == 0)
	{
	  
printf ("Nenhum cliente encontrado.\n");
	
}
      
fclose (arq);
      
break;
    
case 5:
      
char state[64];
      
fflush (stdin);
      
printf ("Digite o estado do cliente:\n");
      
scanf (" %[^\n]s", state);
      
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
while (n != 0)
	{
	  
if (strcmp (state, pessoa.ender.estado) == 0)
	    {
	      
printf ("%d - ", pessoa.id);
	      
printf ("%s\n", pessoa.nome);
	      
printf ("%s", pessoa.ender.rua);
	      
printf (", %d\n", pessoa.ender.numero);
	      
printf ("%s - ", pessoa.ender.cidade);
	      
printf ("%s ", pessoa.ender.estado);
	      
printf ("Tel: %s\n\n", pessoa.telefone);
	      
v++;
	    
}
	  
n = fread (&pessoa, sizeof (struct client), 1, arq);
      
} 
if (v == 0)
	{
	  
printf ("Nenhum cliente encontrado.\n");
	
}
      
fclose (arq);
      
break;
    
default:
      printf ("Nenhum cliente encontrado.\n");
      break;
    
}

 
}


int
main ()
{
  
int escolha;
  
  do
    {
      
printf
	("Escolha uma opcao:\n1-Gravar clientes\n2-Ler clientes\n3-Limpar resgistros\n4-Filtrar clientes\n0-Fechar programa\n");
      
scanf ("%i", &escolha);
      
switch (escolha)
	{
	
case 0:
	  break;
	
case 1:
	  gravar_clientes ();
	  break;
	
case 2:
	  pesquisar_cliente ();
	  break;
	
case 3:
	  limpar ();
	  break;
	
case 4:
	  filtrar_clientes ();
	  break;
	
}
    
}
  while (escolha != 0);

}
