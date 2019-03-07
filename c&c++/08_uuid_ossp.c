/* This is a sample code for using ossp-uuid.
 *
 * INSTALLATION:
 * 1. apt install -y libossp-uuid-dev
 * 2. gcc -o 08_uuid_ossp 08_uuid_ossp.c -lossp-uuid
 *
 * REFERENCES:
 * 1. Download uuid-1.6.2.tar.gz from 
 *    http://www.mirrorservice.org/sites/ftp.ossp.org/pkg/lib/uuid/
 *    untar and find: uuid-1.6.2 -> uuid_cli.c
 * 2. https://en.wikipedia.org/wiki/Universally_unique_identifier
 *
 * HINT:
 * You can check the results with uuid command (apt install -y uuid)
 * Decode with $ uuid -d <UUID>
 */

#include <stdio.h>
#include <stdlib.h>
#include "ossp/uuid.h"

int main(int argc, char *argv[])
{
  uuid_t *uuid;
  uuid_rc_t rc;
  char* output;
  size_t data_len;

  if ((rc = uuid_create(&uuid)) != UUID_RC_OK) {
    printf("[ERROR] uuid_create: %s\n", uuid_error(rc));
    exit(1);
  }

  /* Generate a UUID in Version 1 */
  if ((rc = uuid_make(uuid, UUID_MAKE_V1)) != UUID_RC_OK) {
    printf("[ERROR] uuid_make: %s\n", uuid_error(rc));
    exit(1);
  }

  output = NULL;
  if ((rc = uuid_export(uuid, UUID_FMT_STR, &output, &data_len)) != UUID_RC_OK) {
    printf("[ERROR] uuid_export: %s\n", uuid_error(rc));
    exit(1);
  }

  printf("[SUCCESS] Output UUID Version 1:\n%s\n", output);

  if ((rc = uuid_destroy(uuid)) != UUID_RC_OK) {
    printf("[ERROR] uuid_destroy: %s\n", uuid_error(rc));
    exit(1);
  }
  
  return 0;
}
