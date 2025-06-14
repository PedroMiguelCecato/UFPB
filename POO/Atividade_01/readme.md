1. As classes estão definidas em: Pais.h  Modalidade.h  Atleta.h  e  Medalha.h;

2. Os atributos das classes estão privados, pois não devem ser acessados de outra forma senão através dos métodos;

3. Todas as classes possuem método get_ e set_, além de contrutores parametrizados e não parametrizados;

4. Na main, é possível inicializar as instâncias das classes passando os parâmetros diretamente, parâmetros esses que serão adquiridos através das funções definidas em "Funcoes.h", ou pelos métodos das classes citados acima;

5. Observe que, ao inicializar uma classe Atleta, é necessário usar seu método .set_modalidade() para definir a modalidade do atleta;

6. Observe que os métodos exibe_ existe em cada classe e ao chama-lo para uma instância da classe Medalha, já é obtido as exibições de todas as outras classes, sendo desnecessário a chamada de mais métodos exibe_ de outras classes;