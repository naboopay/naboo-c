#ifndef transaction_response_TEST
#define transaction_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_response.h"
transaction_response_t* instantiate_transaction_response(int include_optional);



transaction_response_t* instantiate_transaction_response(int include_optional) {
  transaction_response_t* transaction_response = NULL;
  if (include_optional) {
    transaction_response = transaction_response_create(
      "0",
      list_createList(),
      56,
      56,
      "0",
      "0",
      "pending",
      1,
      1,
      "0"
    );
  } else {
    transaction_response = transaction_response_create(
      "0",
      list_createList(),
      56,
      56,
      "0",
      "0",
      "pending",
      1,
      1,
      "0"
    );
  }

  return transaction_response;
}


#ifdef transaction_response_MAIN

void test_transaction_response(int include_optional) {
    transaction_response_t* transaction_response_1 = instantiate_transaction_response(include_optional);

	cJSON* jsontransaction_response_1 = transaction_response_convertToJSON(transaction_response_1);
	printf("transaction_response :\n%s\n", cJSON_Print(jsontransaction_response_1));
	transaction_response_t* transaction_response_2 = transaction_response_parseFromJSON(jsontransaction_response_1);
	cJSON* jsontransaction_response_2 = transaction_response_convertToJSON(transaction_response_2);
	printf("repeating transaction_response:\n%s\n", cJSON_Print(jsontransaction_response_2));
}

int main() {
  test_transaction_response(1);
  test_transaction_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_response_MAIN
#endif // transaction_response_TEST
