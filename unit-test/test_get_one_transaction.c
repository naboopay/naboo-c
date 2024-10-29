#ifndef get_one_transaction_TEST
#define get_one_transaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_one_transaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_one_transaction.h"
get_one_transaction_t* instantiate_get_one_transaction(int include_optional);



get_one_transaction_t* instantiate_get_one_transaction(int include_optional) {
  get_one_transaction_t* get_one_transaction = NULL;
  if (include_optional) {
    get_one_transaction = get_one_transaction_create(
      "0",
      list_createList(),
      56,
      56,
      "0",
      "0",
      nabooapi_v1_get_one_transaction__pending,
      list_createList(),
      1,
      1,
      1,
      "0"
    );
  } else {
    get_one_transaction = get_one_transaction_create(
      "0",
      list_createList(),
      56,
      56,
      "0",
      "0",
      nabooapi_v1_get_one_transaction__pending,
      list_createList(),
      1,
      1,
      1,
      "0"
    );
  }

  return get_one_transaction;
}


#ifdef get_one_transaction_MAIN

void test_get_one_transaction(int include_optional) {
    get_one_transaction_t* get_one_transaction_1 = instantiate_get_one_transaction(include_optional);

	cJSON* jsonget_one_transaction_1 = get_one_transaction_convertToJSON(get_one_transaction_1);
	printf("get_one_transaction :\n%s\n", cJSON_Print(jsonget_one_transaction_1));
	get_one_transaction_t* get_one_transaction_2 = get_one_transaction_parseFromJSON(jsonget_one_transaction_1);
	cJSON* jsonget_one_transaction_2 = get_one_transaction_convertToJSON(get_one_transaction_2);
	printf("repeating get_one_transaction:\n%s\n", cJSON_Print(jsonget_one_transaction_2));
}

int main() {
  test_get_one_transaction(1);
  test_get_one_transaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_one_transaction_MAIN
#endif // get_one_transaction_TEST
