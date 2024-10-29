#ifndef get_all_transaction_TEST
#define get_all_transaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_all_transaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_all_transaction.h"
get_all_transaction_t* instantiate_get_all_transaction(int include_optional);



get_all_transaction_t* instantiate_get_all_transaction(int include_optional) {
  get_all_transaction_t* get_all_transaction = NULL;
  if (include_optional) {
    get_all_transaction = get_all_transaction_create(
      list_createList()
    );
  } else {
    get_all_transaction = get_all_transaction_create(
      list_createList()
    );
  }

  return get_all_transaction;
}


#ifdef get_all_transaction_MAIN

void test_get_all_transaction(int include_optional) {
    get_all_transaction_t* get_all_transaction_1 = instantiate_get_all_transaction(include_optional);

	cJSON* jsonget_all_transaction_1 = get_all_transaction_convertToJSON(get_all_transaction_1);
	printf("get_all_transaction :\n%s\n", cJSON_Print(jsonget_all_transaction_1));
	get_all_transaction_t* get_all_transaction_2 = get_all_transaction_parseFromJSON(jsonget_all_transaction_1);
	cJSON* jsonget_all_transaction_2 = get_all_transaction_convertToJSON(get_all_transaction_2);
	printf("repeating get_all_transaction:\n%s\n", cJSON_Print(jsonget_all_transaction_2));
}

int main() {
  test_get_all_transaction(1);
  test_get_all_transaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_all_transaction_MAIN
#endif // get_all_transaction_TEST
