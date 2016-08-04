#include <string.h>

#include "jerry.h"
#include "hal_gpio.h"
#include "microlattice.h"
#include "fota_download_interface.h"

DELCARE_HANDLER(__fota)
{
  int url_req_sz = -jerry_api_string_to_char_buffer (args_p[0].v_string, NULL, 0);
  char * url_buffer = (char*) malloc (url_req_sz);
  url_req_sz = jerry_api_string_to_char_buffer (args_p[0].v_string, url_buffer, url_req_sz);
  url_buffer[url_req_sz] = '\0';

  uint8_t ret;
  ret = fota_download_by_http(url_buffer);
  printf ("fota_download_by_http, ret = %d \r\n", ret);

  ret_val_p->type = JERRY_API_DATA_TYPE_BOOLEAN;
  ret_val_p->v_bool = true;
  return true;
}

void ml_fota_init(void)
{
  REGISTER_HANDLER(__fota);
}