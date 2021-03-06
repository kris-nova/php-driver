#include "php_cassandra.h"
#include "util/result.h"
#include "util/ref.h"
#include "util/types.h"

zend_class_entry *cassandra_default_table_ce = NULL;

PHP_METHOD(DefaultTable, name)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "columnfamily_name", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, comment)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "comment", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, readRepairChance)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "read_repair_chance", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, localReadRepairChance)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "local_read_repair_chance", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, gcGraceSeconds)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "gc_grace_seconds", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, caching)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "caching", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, bloomFilterFPChance)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "bloom_filter_fp_chance", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, memtableFlushPeriodMs)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "memtable_flush_period_in_ms", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, defaultTTL)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "default_time_to_live", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, speculativeRetry)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "speculative_retry", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, indexInterval)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "index_interval", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, compactionStrategyClassName)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "compaction_strategy_class", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, compactionStrategyOptions)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "compaction_strategy_options", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, compressionParameters)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "compression_parameters", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

static zval*
php_cassandra_create_column(cassandra_ref*        schema,
                            const CassSchemaMeta* metadata TSRMLS_DC)
{
  zval*             zcolumn;
  cassandra_column* column;

  const CassSchemaMetaField* field;
  const CassValue*           value;

  const char* validator;
  size_t      validator_length;

  field = cass_schema_meta_get_field(metadata, "validator");
  value = cass_schema_meta_field_value(field);

  ASSERT_SUCCESS_VALUE(cass_value_get_string(value, &validator,
                                             &validator_length), NULL);

  MAKE_STD_ZVAL(zcolumn);
  object_init_ex(zcolumn, cassandra_default_column_ce);

  column = (cassandra_column*) zend_object_store_get_object(zcolumn TSRMLS_CC);

  ASSERT_SUCCESS_BLOCK(php_cassandra_get_schema_field(metadata, "column_name",
                                                      &column->name TSRMLS_CC),
    zval_ptr_dtor(&zcolumn);
    return NULL;
  );

  if (php_cassandra_parse_column_type(validator, validator_length,
                                      &column->reversed, &column->frozen,
                                      &column->type TSRMLS_CC) == FAILURE) {
    zval_ptr_dtor(&zcolumn);
    return NULL;
  }

  column->meta   = metadata;
  column->schema = php_cassandra_add_ref(schema);

  return zcolumn;
}

PHP_METHOD(DefaultTable, column)
{
  cassandra_table* self;
  char* name;
  int   name_len;
  zval* column;
  const CassSchemaMeta* metadata;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
    return;
  }

  self     = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);
  metadata = cass_schema_meta_get_entry(self->meta, name);

  if (metadata == NULL) {
    return;
  }

  column = php_cassandra_create_column(self->schema, metadata TSRMLS_CC);

  if (column == NULL) {
    return;
  }

  RETURN_ZVAL(column, 0, 1);
}

PHP_METHOD(DefaultTable, columns)
{
  cassandra_table*      self;
  const CassSchemaMeta* meta;
  CassIterator*         iterator;
  zval*                 zcolumn;
  cassandra_column*     column;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self     = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);
  iterator = cass_iterator_from_schema_meta(self->meta);

  array_init(return_value);
  while (cass_iterator_next(iterator)) {
    meta    = cass_iterator_get_schema_meta(iterator);
    zcolumn = php_cassandra_create_column(self->schema, meta TSRMLS_CC);

    if (zcolumn == NULL) {
      zval_ptr_dtor(&return_value);
      cass_iterator_free(iterator);
      return;
    } else {
      column = (cassandra_column*) zend_object_store_get_object(zcolumn TSRMLS_CC);

      if (Z_TYPE_P(column->name) == IS_STRING) {
        add_assoc_zval_ex(return_value, Z_STRVAL_P(column->name),
                          Z_STRLEN_P(column->name) + 1, zcolumn);
      } else {
        add_next_index_zval(return_value, zcolumn);
      }
    }
  }

  cass_iterator_free(iterator);
}

PHP_METHOD(DefaultTable, populateIOCacheOnFlush)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "populate_io_cache_on_flush", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, replicateOnWrite)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "replicate_on_write", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, maxIndexInterval)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "max_index_interval", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

PHP_METHOD(DefaultTable, minIndexInterval)
{
  cassandra_table* self;
  zval* value;

  if (zend_parse_parameters_none() == FAILURE)
    return;

  self = (cassandra_table*) zend_object_store_get_object(getThis() TSRMLS_CC);

  php_cassandra_get_schema_field(self->meta, "min_index_interval", &value TSRMLS_CC);
  RETURN_ZVAL(value, 0, 1);
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_name, 0, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_none, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

static zend_function_entry cassandra_default_table_methods[] = {
  PHP_ME(DefaultTable, name, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, comment, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, readRepairChance, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, localReadRepairChance, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, gcGraceSeconds, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, caching, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, bloomFilterFPChance, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, memtableFlushPeriodMs, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, defaultTTL, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, speculativeRetry, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, indexInterval, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, compactionStrategyClassName, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, compactionStrategyOptions, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, compressionParameters, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, populateIOCacheOnFlush, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, replicateOnWrite, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, maxIndexInterval, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, minIndexInterval, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, column, arginfo_name, ZEND_ACC_PUBLIC)
  PHP_ME(DefaultTable, columns, arginfo_none, ZEND_ACC_PUBLIC)
  PHP_FE_END
};

static zend_object_handlers cassandra_default_table_handlers;

static HashTable*
php_cassandra_default_table_properties(zval *object TSRMLS_DC)
{
  HashTable* props = zend_std_get_properties(object TSRMLS_CC);

  return props;
}

static int
php_cassandra_default_table_compare(zval *obj1, zval *obj2 TSRMLS_DC)
{
  if (Z_OBJCE_P(obj1) != Z_OBJCE_P(obj2))
    return 1; /* different classes */

  return Z_OBJ_HANDLE_P(obj1) != Z_OBJ_HANDLE_P(obj1);
}

static void
php_cassandra_default_table_free(void *object TSRMLS_DC)
{
  cassandra_table* table = (cassandra_table*) object;

  zend_object_std_dtor(&table->zval TSRMLS_CC);

  if (table->schema) {
    php_cassandra_del_ref(&table->schema);
    table->schema = NULL;
  }
  table->meta = NULL;

  efree(table);
}

static zend_object_value
php_cassandra_default_table_new(zend_class_entry* class_type TSRMLS_DC)
{
  zend_object_value retval;
  cassandra_table *table;

  table = (cassandra_table*) ecalloc(1, sizeof(cassandra_table));

  zend_object_std_init(&table->zval, class_type TSRMLS_CC);
  object_properties_init(&table->zval, class_type);

  table->meta   = NULL;
  table->schema = NULL;

  retval.handle   = zend_objects_store_put(table,
                      (zend_objects_store_dtor_t) zend_objects_destroy_object,
                      php_cassandra_default_table_free, NULL TSRMLS_CC);
  retval.handlers = &cassandra_default_table_handlers;

  return retval;
}

void cassandra_define_DefaultTable(TSRMLS_D)
{
  zend_class_entry ce;

  INIT_CLASS_ENTRY(ce, "Cassandra\\DefaultTable", cassandra_default_table_methods);
  cassandra_default_table_ce = zend_register_internal_class(&ce TSRMLS_CC);
  zend_class_implements(cassandra_default_table_ce TSRMLS_CC, 1, cassandra_table_ce);
  cassandra_default_table_ce->ce_flags     |= ZEND_ACC_FINAL_CLASS;
  cassandra_default_table_ce->create_object = php_cassandra_default_table_new;

  memcpy(&cassandra_default_table_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
  cassandra_default_table_handlers.get_properties  = php_cassandra_default_table_properties;
  cassandra_default_table_handlers.compare_objects = php_cassandra_default_table_compare;
}
