
#include <stdio.h>
#include <stdlib.h>

#include "aes.h"
#include "gcm.h"

#define TEST_CASE (1)

int main(int argc, char *argv[]) {
	 
#if defined(TEST_CASE) && (TEST_CASE==1)
	uint8_t key[BLOCK_CIPHER_BLOCK_SIZE] = {0};
	uint8_t *input = NULL;
	uint8_t *output = NULL;
	size_t length = 0;
	uint8_t *add = NULL;
	size_t add_len = 0;
	uint8_t iv[DEFAULT_IV_LEN] = {0};
	size_t iv_len = DEFAULT_IV_LEN;

#elif defined(TEST_CASE) && (TEST_CASE==2)
	uint8_t key[BLOCK_CIPHER_BLOCK_SIZE] = {0};
	uint8_t input[BLOCK_CIPHER_BLOCK_SIZE] = {0};
	uint8_t output[BLOCK_CIPHER_BLOCK_SIZE];
	size_t length = BLOCK_CIPHER_BLOCK_SIZE;
	uint8_t *add = NULL;
	size_t add_len = 0;
	uint8_t iv[DEFAULT_IV_LEN] = {0};
	size_t iv_len = DEFAULT_IV_LEN;

#elif defined(TEST_CASE) && (TEST_CASE==3)
	uint8_t key[BLOCK_CIPHER_BLOCK_SIZE] = {
		0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c, 0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08};
	size_t length = BLOCK_CIPHER_BLOCK_SIZE*4;
	uint8_t input[BLOCK_CIPHER_BLOCK_SIZE*4] = {
		0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5, 0xa5, 0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a,
		0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda, 0x2e, 0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
		0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53, 0x2f, 0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
		0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57, 0xba, 0x63, 0x7b, 0x39, 0x1a, 0xaf, 0xd2, 0x55};
	uint8_t output[BLOCK_CIPHER_BLOCK_SIZE*4];
	size_t add_len = 0;
	uint8_t *add = NULL;
	size_t iv_len = DEFAULT_IV_LEN;
	uint8_t iv[DEFAULT_IV_LEN] = {
		0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad, 0xde, 0xca, 0xf8, 0x88};

#elif defined(TEST_CASE) && (TEST_CASE==4)
	uint8_t key[BLOCK_CIPHER_BLOCK_SIZE] = {
		0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c, 0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08};
	size_t length = BLOCK_CIPHER_BLOCK_SIZE*3+DEFAULT_IV_LEN;
	uint8_t input[BLOCK_CIPHER_BLOCK_SIZE*3+DEFAULT_IV_LEN] = {
		0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5, 0xa5, 0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a,
		0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda, 0x2e, 0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
		0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53, 0x2f, 0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
		0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57, 0xba, 0x63, 0x7b, 0x39};
	uint8_t output[BLOCK_CIPHER_BLOCK_SIZE*3+DEFAULT_IV_LEN];
	size_t add_len = BLOCK_CIPHER_BLOCK_SIZE+4;
	uint8_t add[BLOCK_CIPHER_BLOCK_SIZE+4] = {
		0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,
		0xab, 0xad, 0xda, 0xd2};
	size_t iv_len = DEFAULT_IV_LEN;
	uint8_t iv[DEFAULT_IV_LEN] = {
		0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad, 0xde, 0xca, 0xf8, 0x88};

#elif defined(TEST_CASE) && (TEST_CASE==5)
	uint8_t key[BLOCK_CIPHER_BLOCK_SIZE] = {
		0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c, 0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08};
	size_t length = BLOCK_CIPHER_BLOCK_SIZE*3+DEFAULT_IV_LEN;
	uint8_t input[BLOCK_CIPHER_BLOCK_SIZE*3+DEFAULT_IV_LEN] = {
		0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5, 0xa5, 0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a,
		0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda, 0x2e, 0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
		0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53, 0x2f, 0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
		0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57, 0xba, 0x63, 0x7b, 0x39};
	uint8_t output[BLOCK_CIPHER_BLOCK_SIZE*3+DEFAULT_IV_LEN];
	size_t add_len = BLOCK_CIPHER_BLOCK_SIZE+4;
	uint8_t add[BLOCK_CIPHER_BLOCK_SIZE+4] = {
		0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,
		0xab, 0xad, 0xda, 0xd2};
	size_t iv_len = DEFAULT_IV_LEN-4;
	uint8_t iv[DEFAULT_IV_LEN-4] = {
		0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad};
#endif

	uint8_t tag[16] = {0};
	size_t tag_len = 16;
	
	void * context = mbedtls_gcm_init();
	if ( !context ) { 
		printf("malloc failed.\n");
		return 0;
	}
	
	int flag = -2;
	flag = mbedtls_gcm_setkey( context, (const unsigned char *)key, 128 );

	if ( MBEDTLS_BLOCK_CIPHER_FAIL != flag ) {
		mbedtls_gcm_crypt_and_tag( context,
			(const unsigned char *)iv,
			iv_len,
			(const unsigned char *)add,
			add_len,
			(const unsigned char *)input,
			length,
			(unsigned char *)output,
			(unsigned char *)tag,
			tag_len);

		printf("Tag:            ");
		uint8_t i;
		for (i = 0; i < 4; i++) {
			printf("%x %x %x %x ", tag[4*i+0], tag[4*i+1], tag[4*i+2], tag[4*i+3]);
		}
		printf("\n");
	}

	mbedtls_gcm_free( context);

	return 0;

}
