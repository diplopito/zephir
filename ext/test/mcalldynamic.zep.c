
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Method calls
 */
ZEPHIR_INIT_CLASS(Test_McallDynamic) {

	ZEPHIR_REGISTER_CLASS(Test, McallDynamic, test, mcalldynamic, test_mcalldynamic_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Test_McallDynamic, testMethod1) {

	zval *this_ptr = getThis();


	RETURN_LONG(1);

}

PHP_METHOD(Test_McallDynamic, testMagicCall1) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "method1", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "method1", NULL, 0);
	zephir_check_call_status();
	zephir_add_function(return_value, &_0, &_1);
	RETURN_MM();

}

PHP_METHOD(Test_McallDynamic, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *arguments, arguments_sub, realMethod;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&realMethod);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &arguments);



	ZEPHIR_INIT_VAR(&realMethod);
	ZEPHIR_CONCAT_SV(&realMethod, "test", method);
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &realMethod, NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

