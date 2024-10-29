#ifndef product_model_TEST
#define product_model_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define product_model_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/product_model.h"
product_model_t* instantiate_product_model(int include_optional);



product_model_t* instantiate_product_model(int include_optional) {
  product_model_t* product_model = NULL;
  if (include_optional) {
    product_model = product_model_create(
      "0",
      "0",
      56,
      56,
      "0"
    );
  } else {
    product_model = product_model_create(
      "0",
      "0",
      56,
      56,
      "0"
    );
  }

  return product_model;
}


#ifdef product_model_MAIN

void test_product_model(int include_optional) {
    product_model_t* product_model_1 = instantiate_product_model(include_optional);

	cJSON* jsonproduct_model_1 = product_model_convertToJSON(product_model_1);
	printf("product_model :\n%s\n", cJSON_Print(jsonproduct_model_1));
	product_model_t* product_model_2 = product_model_parseFromJSON(jsonproduct_model_1);
	cJSON* jsonproduct_model_2 = product_model_convertToJSON(product_model_2);
	printf("repeating product_model:\n%s\n", cJSON_Print(jsonproduct_model_2));
}

int main() {
  test_product_model(1);
  test_product_model(0);

  printf("Hello world \n");
  return 0;
}

#endif // product_model_MAIN
#endif // product_model_TEST
