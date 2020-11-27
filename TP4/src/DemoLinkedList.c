#include "../inc/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

void demostracion_Sub_Len_IsEmpty(LinkedList* lista1,LinkedList** lista2)
{
//-----------------------------------(Utilizacion de ll_sublist, ll_len, ll_isEmpty)--------------------------------------------

    printf("Se tienen 1 lista de empleados:\n\n Lista 1:\n\n");
    controller_ListEmployee(lista1);

    system("cls");
    printf("De esa lista se crea una sublista con los primeros 10.\n\n");
    *lista2 = ll_subList(lista1, 0, 10);
    system("pause");

    system("cls");
    printf("Checkeamos que ambas listas no esten vacias y que los largos sean los esperados.");
    printf("\n\nLista 1 esta vacia: ");
    if(ll_isEmpty(lista1)){printf("SI");}
    else
    {
        printf("NO\n");
        printf("Largo de lista: %i\n\n" , ll_len(lista1));
    }
    printf("\n\nLista 2 esta vacia: ");
    if(ll_isEmpty(*lista2)){printf("SI");}
    else
    {
        printf("NO\n");
        printf("Largo de lista: %i\n\n" , ll_len(*lista2));
    }
    system("pause");
//------------------------------------------------------------------------------------------------------------------------------
}

void demostracion_Pop_Set_Contains_Get_Sort(LinkedList* lista1,LinkedList* lista2)
{
//-----------------------------------(Utilizacion de ll_pop, ll_set, ll_contains, ll_get, ll_sort)------------------------------

    system("cls");
    printf("Ahora voy a pasar el empleado numero 15 de la Lista 1 a la Lista 2 a traves de la funcion pop y luego add.\n\nLista 1:\n\n");
    ll_add(lista2, ll_pop(lista1, 14));
    controller_ListEmployee(lista1);
    printf("\nLista 2\n\n");
    controller_ListEmployee(lista2);

    system("cls");
    printf("Luego supongamos que necesito que el empleado de mayor salario de la lista 1 este en ambas listas.\n\n Primero ordeno la lista 1 por salario:\nLista 1:\n\n");
    ll_sort(lista1, compararPorSueldo, 0);
    controller_ListEmployee(lista1);
    system("cls");
    printf("Luego utilizo ll_contains para checkear si el empleado de indice 0 de la lista 1 esta en la lista 2.\n\n El empleado esta en la lista 2:  ");
    if(ll_contains(lista2, ll_get(lista1, 0)))
    {
        printf("SI\n");
    }
    else
    {
        printf("NO\n");
        printf("\n\nComo el empleado no se encuentra voy a agregarlo, pero supongamos que necesito que el tamanio de la lista dos se mantenga\ncomo esta, entonces voy a sacar el empleado con el menor sueldo de la lista 2.\n\n");
        printf("Primero voy a ordenar la lista 2 por sueldo ascendente y luego utilizar ll_set para \nubicar el nuevo empleado en el indice 0 y asi reemplazar al de menor sueldo. \n\nLista 2 luego del cambio:\n\n");
        ll_sort(lista2, compararPorSueldo, 1);
        ll_set(lista2, 0, ll_get(lista1, 0));
        controller_ListEmployee(lista2);
    }

    ll_sort(lista2, compararPorId, 1);

//------------------------------------------------------------------------------------------------------------------------------
}

void demostracion_Push_IndexOf_Pop(LinkedList* lista1,LinkedList* lista2)
{
//-----------------------------------(Utilizacion de ll_push, ll_indexOf, ll_pop)-----------------------------------------------


    system("cls");
    printf("Ahora supongamos que tengo que agregar el jefe de la compania a la lista, pero el quiere estar primero mas alla del ordenamiento, \npara esto voy a utilizar la funcion push para agregarlo en el primer lugar de la lista.\n\n");
    Employee* jefe = employee_newParametros(0, "JEFE", 4, 50000);
    ll_push(lista1, 0, jefe );
    printf("Lista 1:\n");
    controller_ListEmployee(lista1);
    printf("\nObviamente esta condicion se perderia al primer ordenamiento (o quizas no) pero solo es para mostrar el funcionamiento de ll_push, \ntengase en cuenta que como fue la primera posicion, podria haber sido cualquiera dentro de la lista.\n\n");
    system("pause");

    ll_sort(lista1, compararPorSueldo, 1);

    system("cls");
    printf("Ahora podriamos ver que pasa si el jefe ya esta en la lista y quiere ser pasado al primer lugar, el estado de la lista es el siguiente:\n\n");
    controller_ListEmployee(lista1);
    printf("\n\n Para resolverlo usamos ll_indexOf en la lista y obtenemos el indice en que se encuentra el jefe y luego volvemos a utilizar las funciones pop y push.\n\n");
    system("pause");
    system("cls");
    printf("Indice anterior del jefe : %i\n\n" , ll_indexOf(lista1, jefe));
    printf("Lista 1 luego del cambio:\n\n");
    ll_push(lista1, 0, ll_pop(lista1, ll_indexOf(lista1, jefe)));
    controller_ListEmployee(lista1);

//---------------------------------------------------------------------------------------------------------------------------------
}

void demostracion_ContainsAll_Contains_Add(LinkedList* lista1,LinkedList* lista2)
{
//-----------------------------------(Utilizacion de ll_containsAll, ll_contains, ll_add)--------------------------------------------

    system("cls");
    printf("El siguiente paso podria ser que debieramos checkear que todos mis empleados en la lista 2\n tambien esten en la lista 1, ya que es una sublista de la misma, \npara esto usaremos la funcion ll_containsAll.");
    printf("\n\nEstan todos en ls lista 1:  ");
    if(ll_containsAll(lista1, lista2))
    {
        printf("SI\n\n");
    }
    else
    {
        printf("NO\n\n");
        printf("Para buscar el indice del empleado no contenido se debe desarrollar un algoritmo propio, \npero dentro de este utilizaremos la funcion ll_contains y ll_get.\n\n");
        int indiceEmpleado = 0;
        int i = 0;
        while(!indiceEmpleado)
        {
            if(ll_contains(lista1, ll_get(lista2, i)))
            {
                i++;
            }
            else
            {
                indiceEmpleado = i;
            }
        }
        printf("Indice del empleado no contenido:  %i\n\n", indiceEmpleado);
        ll_add(lista1, ll_get(lista2, indiceEmpleado));
    }
    system("pause");
    system("cls");
    printf("Luego de haber agregado el empleado con ese indice volvemos a checkear si ahora estan todos contenidos:");
    printf("\n\nEstan todos en ls lista 1:  ");
    if(ll_containsAll(lista1, lista2))
    {
        printf("SI\n\n");
    }
    else
    {
        printf("NO\n\n");
    }
    system("pause");

//------------------------------------------------------------------------------------------------------------------------------------
}

void demostracion_Clear_Delete(LinkedList* lista1,LinkedList* lista2)
{
//-----------------------------------(Utilizacion de ll_clear y ll_delteLinkedList)--------------------------------------------

    system("cls");
    printf("Finalmente habiendo ya guardado mis listas como archivos supongamos que las quiero borrar para luego trabajar con otra cosa.\nPara esto utilizaremos la funcion ll_clear y luego ll_deleteLinkedList.\n");
    printf("Esto no seria necesario ya que ll_delete llama a ll_clear dentro de su funcionamiento,\npero vamos a mostrar la diferencia para la demostracion.\n\n");
    ll_clear(lista1);
    printf("Lista 1 luego del clear:\n\n");
    printf("Lista esta vacia: ");
    if(ll_isEmpty(lista1))
    {
        printf("SI\n\n");
    }
    else
    {
        printf("NO\n\n");
    }
    printf("Largo de lista: %i\n\n", ll_len(lista1));

    printf("Como se ve, la lista esta vacia, pero aun puedo utilizarla, lo cual no sucede con ll_delete.\n");
    printf("Lista 1 luego de ll_delete:\n\n");

    ll_deleteLinkedList(lista1);
    lista1 = NULL; //Esto seria "hacer trampa" pero como lista1 tiene una direccion a basura y no NULL las funciones de linked list siguen tomandolo como un puntero correcto.

    printf("Retorno de ll_isEmpty: %i\n\n", ll_isEmpty(lista1));
    printf("Como se ve, -1 es un retorno de error, por lo tanto esa lista ya no se puede utilizar, deberia crear una nueva.\n\n");
    system("pause");

//-----------------------------------------------------------------------------------------------------------------------------
}

int comenzarDemoLinkedList()
{
    LinkedList* lista1 = ll_newLinkedList();
    LinkedList* lista2 = ll_newLinkedList();
    controller_loadFromText("Lista1.csv", lista1);

    demostracion_Sub_Len_IsEmpty(lista1, &lista2);
    demostracion_Pop_Set_Contains_Get_Sort(lista1, lista2);
    demostracion_Push_IndexOf_Pop(lista1, lista2);
    demostracion_ContainsAll_Contains_Add(lista1, lista2);
    demostracion_Clear_Delete(lista1, lista2);

    printf("---------------FIN  DE LA DEMOSTRACION---------------");

    return 0;
}


