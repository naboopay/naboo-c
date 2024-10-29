#ifndef transaction_status_enum_TEST
#define transaction_status_enum_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_status_enum_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_status_enum.h"
transaction_status_enum_t* instantiate_transaction_status_enum(int include_optional);



transaction_status_enum_t* instantiate_transaction_status_enum(int include_optional) {
  transaction_status_enum_t* transaction_status_enum = NULL;
  if (include_optional) {
    transaction_status_enum = transaction_status_enum_create(
    );
  } else {
    transaction_status_enum = transaction_status_enum_create(
    );
  }

  return transaction_status_enum;
}


#ifdef transaction_status_enum_MAIN

void test_transaction_status_enum(int include_optional) {
    transaction_status_enum_t* transaction_status_enum_1 = instantiate_transaction_status_enum(include_optional);

	cJSON* jsontransaction_status_enum_1 = transaction_status_enum_convertToJSON(transaction_status_enum_1);
	printf("transaction_status_enum :\n%s\n", cJSON_Print(jsontransaction_status_enum_1));
	transaction_status_enum_t* transaction_status_enum_2 = transaction_status_enum_parseFromJSON(jsontransaction_status_enum_1);
	cJSON* jsontransaction_status_enum_2 = transaction_status_enum_convertToJSON(transaction_status_enum_2);
	printf("repeating transaction_status_enum:\n%s\n", cJSON_Print(jsontransaction_status_enum_2));
}

int main() {
  test_transaction_status_enum(1);
  test_transaction_status_enum(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_status_enum_MAIN
#endif // transaction_status_enum_TEST
