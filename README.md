# generic-list-c
Lista di tipo generico in C
---------------------------
Per l'inserimento bisogna passare come argomento un puntatore a void che punta all'elemento da inserire :
---------------------------
  LIST list = List(); //Iniziallizazione lista.
  
  int a = 100, b = 200;
  
  char *str = "ciao";
  
  void *ptr;
  
  ptr = &a;
  
  list.insert(&list, ptr);
  
  ptr = &b;
  
  list.insert(&list, ptr);
  
  ptr = str;
  
  list.insert(&list, ptr);
  
-------------------------------------------------------------------
Per estrarre un elemento bisogna convertirlo con le marco integrate:
  - TO_INT()
  - TO_CHAR()
  - TO_STRING()
-------------------------------------------------------------------
  int a = TO_INT(list.getElement(&list, 0));
  
  char c = TO_CHAR(list.getElement(&list, 1));
  
  char *str = TO_STRING(list.getElement(&list, 2));
  
 
