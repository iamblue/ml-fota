#include <string.h>

#include "jerry-api.h"
#include "hal_gpio.h"
#include "microlattice.h"
#include "fota_download_interface.h"

DELCARE_HANDLER(__fota)
{
  jerry_size_t url_req_sz = jerry_get_string_size (args_p[0]);
  jerry_char_t url_buffer[url_req_sz];
  jerry_string_to_char_buffer (args_p[0], url_buffer, url_req_sz);
  url_buffer[url_req_sz] = '\0';

  uint8_t ret;
  ret = fota_download_by_http(url_buffer);
  printf ("fota_download_by_http, ret = %d \r\n", ret);

  return jerry_create_boolean(true);
}

void ml_fota_init(void)
{
  REGISTER_HANDLER(__fota);
}