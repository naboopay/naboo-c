#ifndef delete_transaction_response_TEST
#define delete_transaction_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_transaction_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_transaction_response.h"
delete_transaction_response_t* instantiate_delete_transaction_response(int include_optional);



delete_transaction_response_t* instantiate_delete_transaction_response(int include_optional) {
  delete_transaction_response_t* delete_transaction_response = NULL;
  if (include_optional) {
    delete_transaction_response = delete_transaction_response_create(
      "0",
      "0"
    );
  } else {
    delete_transaction_response = delete_transaction_response_create(
      "0",
      "0"
    );
  }

  return delete_transaction_response;
}


#ifdef delete_transaction_response_MAIN

void test_delete_transaction_response(int include_optional) {
    delete_transaction_response_t* delete_transaction_response_1 = instantiate_delete_transaction_response(include_optional);

	cJSON* jsondelete_transaction_response_1 = delete_transaction_response_convertToJSON(delete_transaction_response_1);
	printf("delete_transaction_response :\n%s\n", cJSON_Print(jsondelete_transaction_response_1));
	delete_transaction_response_t* delete_transaction_response_2 = delete_transaction_response_parseFromJSON(jsondelete_transaction_response_1);
	cJSON* jsondelete_transaction_response_2 = delete_transaction_response_convertToJSON(delete_transaction_response_2);
	printf("repeating delete_transaction_response:\n%s\n", cJSON_Print(jsondelete_transaction_response_2));
}

int main() {
  test_delete_transaction_response(1);
  test_delete_transaction_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_transaction_response_MAIN
#endif // delete_transaction_response_TEST
