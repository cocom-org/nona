#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ird.h"


#line 128 "./ird.sprut"


/* All internal representation storage is implemented by object stack.  See
   package `object-stack'. */

os_t irp;


#line 17 "ird.c"
#ifndef IR_START_ALLOC
#define IR_START_ALLOC()
#endif

#ifndef IR_STOP_ALLOC
#define IR_STOP_ALLOC()
#endif

#ifndef IR_ALLOC
#define IR_ALLOC(ptr, size, ptr_type) ((ptr) = (ptr_type) malloc (size))
#endif

#ifndef IR_FREE
#define IR_FREE(ptr, size) free (ptr)
#endif

#ifndef IR_BEGIN_IR_node_t
#define IR_BEGIN_IR_node_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_IR_node_t
#define IR_END_IR_node_t(a)
#endif

#ifndef IR_COPY_IR_node_t
#define IR_COPY_IR_node_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_IR_node_t
#define IR_EQUAL_IR_node_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_IR_node_t
#define IR_PRINT_IR_node_t(a) printf ("%lx", (unsigned long) (a))
#endif

#ifndef IR_INPUT_IR_node_t
#define IR_INPUT_IR_node_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_IR_node_t
#define IR_OUTPUT_IR_node_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_integer_t
#define IR_BEGIN_integer_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_integer_t
#define IR_END_integer_t(a)
#endif

#ifndef IR_COPY_integer_t
#define IR_COPY_integer_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_integer_t
#define IR_EQUAL_integer_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_integer_t
#define IR_PRINT_integer_t(a)
#endif

#ifndef IR_INPUT_integer_t
#define IR_INPUT_integer_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_integer_t
#define IR_OUTPUT_integer_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_bool_t
#define IR_BEGIN_bool_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_bool_t
#define IR_END_bool_t(a)
#endif

#ifndef IR_COPY_bool_t
#define IR_COPY_bool_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_bool_t
#define IR_EQUAL_bool_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_bool_t
#define IR_PRINT_bool_t(a)
#endif

#ifndef IR_INPUT_bool_t
#define IR_INPUT_bool_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_bool_t
#define IR_OUTPUT_bool_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_string_t
#define IR_BEGIN_string_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_string_t
#define IR_END_string_t(a)
#endif

#ifndef IR_COPY_string_t
#define IR_COPY_string_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_string_t
#define IR_EQUAL_string_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_string_t
#define IR_PRINT_string_t(a)
#endif

#ifndef IR_INPUT_string_t
#define IR_INPUT_string_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_string_t
#define IR_OUTPUT_string_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_position_t
#define IR_BEGIN_position_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_position_t
#define IR_END_position_t(a)
#endif

#ifndef IR_COPY_position_t
#define IR_COPY_position_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_position_t
#define IR_EQUAL_position_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_position_t
#define IR_PRINT_position_t(a)
#endif

#ifndef IR_INPUT_position_t
#define IR_INPUT_position_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_position_t
#define IR_OUTPUT_position_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

short _IR_node_level [] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

unsigned char _IR_SF_node [] =
{255, 255, 31
};

unsigned char _IR_SF_identifier [] =
{2, 0, 0
};

unsigned char _IR_SF_code_insertion [] =
{4, 0, 0
};

unsigned char _IR_SF_expression [] =
{8, 0, 0
};

unsigned char _IR_SF_declaration [] =
{240, 63, 0
};

unsigned char _IR_SF_identifier_declaration [] =
{224, 1, 0
};

unsigned char _IR_SF_term_declaration [] =
{64, 0, 0
};

unsigned char _IR_SF_commutative_declaration [] =
{128, 0, 0
};

unsigned char _IR_SF_type_declaration [] =
{0, 1, 0
};

unsigned char _IR_SF_code [] =
{0, 62, 0
};

unsigned char _IR_SF_local_code [] =
{0, 4, 0
};

unsigned char _IR_SF_import_code [] =
{0, 8, 0
};

unsigned char _IR_SF_export_code [] =
{0, 16, 0
};

unsigned char _IR_SF_union_code [] =
{0, 32, 0
};

unsigned char _IR_SF_rule [] =
{0, 64, 0
};

unsigned char _IR_SF_pattern [] =
{0, 128, 0
};

unsigned char _IR_SF_additional_code [] =
{0, 0, 1
};

unsigned char _IR_SF_description [] =
{0, 0, 2
};

unsigned char _IR_SF_single_declaration [] =
{0, 0, 28
};

unsigned char _IR_SF_single_term_declaration [] =
{0, 0, 8
};

unsigned char _IR_SF_single_nonterm_declaration [] =
{0, 0, 16
};

unsigned char _IR_SF__root [] =
{255, 255, 127
};

unsigned char _IR_SF__error [] =
{0, 0, 64
};

unsigned char *_IR_is_type[] =
{
_IR_SF_node,
_IR_SF_identifier,
_IR_SF_code_insertion,
_IR_SF_expression,
_IR_SF_declaration,
_IR_SF_identifier_declaration,
_IR_SF_term_declaration,
_IR_SF_commutative_declaration,
_IR_SF_type_declaration,
_IR_SF_code,
_IR_SF_local_code,
_IR_SF_import_code,
_IR_SF_export_code,
_IR_SF_union_code,
_IR_SF_rule,
_IR_SF_pattern,
_IR_SF_additional_code,
_IR_SF_description,
_IR_SF_single_declaration,
_IR_SF_single_term_declaration,
_IR_SF_single_nonterm_declaration,
_IR_SF__root,
_IR_SF__error
};

unsigned char _IR_D_type [] =
{
  0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)
    + _IR_offsetof (struct _IR_S_identifier_declaration, type), 
  _IR_offsetof (_IR_term_declaration, _IR_S_term_declaration)
    + _IR_offsetof (struct _IR_S_term_declaration, _IR_M_identifier_declaration)
    + _IR_offsetof (struct _IR_S_identifier_declaration, type), 
  _IR_offsetof (_IR_commutative_declaration, _IR_S_commutative_declaration)
    + _IR_offsetof (struct _IR_S_commutative_declaration, _IR_M_identifier_declaration)
    + _IR_offsetof (struct _IR_S_identifier_declaration, type), 
  _IR_offsetof (_IR_type_declaration, _IR_S_type_declaration)
    + _IR_offsetof (struct _IR_S_type_declaration, _IR_M_identifier_declaration)
    + _IR_offsetof (struct _IR_S_identifier_declaration, type), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)
    + _IR_offsetof (struct _IR_S_single_declaration, type), 
  _IR_offsetof (_IR_single_term_declaration, _IR_S_single_term_declaration)
    + _IR_offsetof (struct _IR_S_single_term_declaration, _IR_M_single_declaration)
    + _IR_offsetof (struct _IR_S_single_declaration, type), 
  _IR_offsetof (_IR_single_nonterm_declaration, _IR_S_single_nonterm_declaration)
    + _IR_offsetof (struct _IR_S_single_nonterm_declaration, _IR_M_single_declaration)
    + _IR_offsetof (struct _IR_S_single_declaration, type), 
  0, 0
};

unsigned char _IR_D_identifier [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_pattern, _IR_S_pattern)
    + _IR_offsetof (struct _IR_S_pattern, identifier), 
  0, 0, 
  _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)
    + _IR_offsetof (struct _IR_S_single_declaration, identifier), 
  _IR_offsetof (_IR_single_term_declaration, _IR_S_single_term_declaration)
    + _IR_offsetof (struct _IR_S_single_term_declaration, _IR_M_single_declaration)
    + _IR_offsetof (struct _IR_S_single_declaration, identifier), 
  _IR_offsetof (_IR_single_nonterm_declaration, _IR_S_single_nonterm_declaration)
    + _IR_offsetof (struct _IR_S_single_nonterm_declaration, _IR_M_single_declaration)
    + _IR_offsetof (struct _IR_S_single_declaration, identifier), 
  0, 0
};

void *_IR_class_structure_array [] =
{
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
};

const char *IR_node_name[] =
{
  "node",
  "identifier",
  "code_insertion",
  "expression",
  "declaration",
  "identifier_declaration",
  "term_declaration",
  "commutative_declaration",
  "type_declaration",
  "code",
  "local_code",
  "import_code",
  "export_code",
  "union_code",
  "rule",
  "pattern",
  "additional_code",
  "description",
  "single_declaration",
  "single_term_declaration",
  "single_nonterm_declaration",
  "%root",
  "%error"
};

unsigned char IR_node_size[] =
{
  sizeof (_IR_node),
  sizeof (_IR_identifier),
  sizeof (_IR_code_insertion),
  sizeof (_IR_expression),
  sizeof (_IR_declaration),
  sizeof (_IR_identifier_declaration),
  sizeof (_IR_term_declaration),
  sizeof (_IR_commutative_declaration),
  sizeof (_IR_type_declaration),
  sizeof (_IR_code),
  sizeof (_IR_local_code),
  sizeof (_IR_import_code),
  sizeof (_IR_export_code),
  sizeof (_IR_union_code),
  sizeof (_IR_rule),
  sizeof (_IR_pattern),
  sizeof (_IR_additional_code),
  sizeof (_IR_description),
  sizeof (_IR_single_declaration),
  sizeof (_IR_single_term_declaration),
  sizeof (_IR_single_nonterm_declaration),
  sizeof (_IR__root),
  sizeof (_IR__error)
};

static int (* _IR_traverse_guard_function_variable) (IR_node_t node);

static int _IR_current_graph_pass_number;

void _IR_set_double_field_value
  (IR_double_link_t link, IR_node_t value, int disp, int flag)
{
}

IR_double_link_t IR__first_double_link (IR_node_t node)
{
  return NULL;
}

void IR__set_double_link (IR_double_link_t link, IR_node_t value)
{
#ifdef __IR_DEBUG__
  if (link == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  (*link->set_function) (link->link_owner, value);
}

static void _IR_node_field_initiation (IR_node_mode_t node_mode, IR_node_t node)
{
  switch (node_mode)
    {
    case IR_NM_node:
      IR_BEGIN_position_t ((((_IR_node *) node)->_IR_S_node.position));
      break;
    case IR_NM_identifier:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_identifier *) node)->_IR_S_identifier._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_identifier *) node)->_IR_S_identifier.identifier_itself));
      IR_BEGIN_IR_node_t ((((_IR_identifier *) node)->_IR_S_identifier.next_identifier));
      break;
    case IR_NM_code_insertion:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_code_insertion *) node)->_IR_S_code_insertion._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_code_insertion *) node)->_IR_S_code_insertion.code_insertion_itself));
      break;
    case IR_NM_expression:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_expression *) node)->_IR_S_expression._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_expression *) node)->_IR_S_expression.expression_itself));
      break;
    case IR_NM_declaration:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_declaration *) node)->_IR_S_declaration._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_declaration *) node)->_IR_S_declaration.next_declaration));
      break;
    case IR_NM_identifier_declaration:
      _IR_node_field_initiation (IR_NM_declaration, (IR_node_t) ((char *) &((_IR_identifier_declaration *) node)->_IR_S_identifier_declaration._IR_M_declaration - _IR_offsetof (_IR_declaration, _IR_S_declaration)));
      IR_BEGIN_IR_node_t ((((_IR_identifier_declaration *) node)->_IR_S_identifier_declaration.identifier_list));
      IR_BEGIN_IR_node_t ((((_IR_identifier_declaration *) node)->_IR_S_identifier_declaration.type));
      break;
    case IR_NM_term_declaration:
      _IR_node_field_initiation (IR_NM_identifier_declaration, (IR_node_t) ((char *) &((_IR_term_declaration *) node)->_IR_S_term_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)));
      break;
    case IR_NM_commutative_declaration:
      _IR_node_field_initiation (IR_NM_identifier_declaration, (IR_node_t) ((char *) &((_IR_commutative_declaration *) node)->_IR_S_commutative_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)));
      break;
    case IR_NM_type_declaration:
      _IR_node_field_initiation (IR_NM_identifier_declaration, (IR_node_t) ((char *) &((_IR_type_declaration *) node)->_IR_S_type_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)));
      break;
    case IR_NM_code:
      _IR_node_field_initiation (IR_NM_declaration, (IR_node_t) ((char *) &((_IR_code *) node)->_IR_S_code._IR_M_declaration - _IR_offsetof (_IR_declaration, _IR_S_declaration)));
      IR_BEGIN_IR_node_t ((((_IR_code *) node)->_IR_S_code.code_itself));
      break;
    case IR_NM_local_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_local_code *) node)->_IR_S_local_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_import_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_import_code *) node)->_IR_S_import_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_export_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_export_code *) node)->_IR_S_export_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_union_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_union_code *) node)->_IR_S_union_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_rule:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_rule *) node)->_IR_S_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.nonterm_identifier));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.pattern));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.optional_cost));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.optional_constraint));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.optional_action));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.next_rule));
      IR_BEGIN_bool_t ((((_IR_rule *) node)->_IR_S_rule.new_commutative_rule_flag));
      IR_BEGIN_integer_t ((((_IR_rule *) node)->_IR_S_rule.rule_number));
      IR_BEGIN_integer_t ((((_IR_rule *) node)->_IR_S_rule.nonterm_rule_number));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.next_nonterm_rule));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.next_chain_rule));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.textual_pattern_list));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.single_nonterm_declaration));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.next_term_rule));
      break;
    case IR_NM_pattern:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_pattern *) node)->_IR_S_pattern._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_pattern *) node)->_IR_S_pattern.identifier));
      IR_BEGIN_IR_node_t ((((_IR_pattern *) node)->_IR_S_pattern.pattern_list));
      IR_BEGIN_IR_node_t ((((_IR_pattern *) node)->_IR_S_pattern.next_pattern));
      IR_BEGIN_integer_t ((((_IR_pattern *) node)->_IR_S_pattern.original_number));
      IR_BEGIN_bool_t ((((_IR_pattern *) node)->_IR_S_pattern.commutative_process_flag));
      IR_BEGIN_IR_node_t ((((_IR_pattern *) node)->_IR_S_pattern.single_declaration));
      IR_BEGIN_IR_node_t ((((_IR_pattern *) node)->_IR_S_pattern.next_textual_pattern));
      IR_BEGIN_integer_t ((((_IR_pattern *) node)->_IR_S_pattern.textual_nonterminal_pattern_number));
      IR_BEGIN_IR_node_t ((((_IR_pattern *) node)->_IR_S_pattern.father));
      break;
    case IR_NM_additional_code:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_additional_code *) node)->_IR_S_additional_code._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_additional_code *) node)->_IR_S_additional_code.additional_code_itself));
      break;
    case IR_NM_description:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_description *) node)->_IR_S_description._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.declaration_list));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.rule_list));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.additional_code));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.single_declaration_list));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.number_of_nonterminals));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.max_number_of_rule_nonterminals));
      break;
    case IR_NM_single_declaration:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_single_declaration *) node)->_IR_S_single_declaration._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_single_declaration *) node)->_IR_S_single_declaration.identifier));
      IR_BEGIN_IR_node_t ((((_IR_single_declaration *) node)->_IR_S_single_declaration.next_single_declaration));
      IR_BEGIN_IR_node_t ((((_IR_single_declaration *) node)->_IR_S_single_declaration.type));
      break;
    case IR_NM_single_term_declaration:
      _IR_node_field_initiation (IR_NM_single_declaration, (IR_node_t) ((char *) &((_IR_single_term_declaration *) node)->_IR_S_single_term_declaration._IR_M_single_declaration - _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)));
      IR_BEGIN_bool_t ((((_IR_single_term_declaration *) node)->_IR_S_single_term_declaration.commutative_flag));
      IR_BEGIN_position_t ((((_IR_single_term_declaration *) node)->_IR_S_single_term_declaration.first_position_in_rules));
      IR_BEGIN_IR_node_t ((((_IR_single_term_declaration *) node)->_IR_S_single_term_declaration.term_rule_list));
      IR_BEGIN_integer_t ((((_IR_single_term_declaration *) node)->_IR_S_single_term_declaration.arity));
      break;
    case IR_NM_single_nonterm_declaration:
      _IR_node_field_initiation (IR_NM_single_declaration, (IR_node_t) ((char *) &((_IR_single_nonterm_declaration *) node)->_IR_S_single_nonterm_declaration._IR_M_single_declaration - _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)));
      IR_BEGIN_integer_t ((((_IR_single_nonterm_declaration *) node)->_IR_S_single_nonterm_declaration.number_of_nonterminal_rules));
      IR_BEGIN_IR_node_t ((((_IR_single_nonterm_declaration *) node)->_IR_S_single_nonterm_declaration.nonterm_rule_list));
      IR_BEGIN_IR_node_t ((((_IR_single_nonterm_declaration *) node)->_IR_S_single_nonterm_declaration.chain_rule_list));
      IR_BEGIN_bool_t ((((_IR_single_nonterm_declaration *) node)->_IR_S_single_nonterm_declaration.derivability_flag));
      IR_BEGIN_integer_t ((((_IR_single_nonterm_declaration *) node)->_IR_S_single_nonterm_declaration.traverse_number));
      break;
    case IR_NM__error:
      break;
    default:
      abort ();
      break;
    }
}

IR_node_t IR_create_node (IR_node_mode_t node_mode)
{
 IR_node_t _result;

  IR_ALLOC (_result, IR_node_size [node_mode], IR_node_t);
#ifdef __IR_DEBUG__
  if (_result == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  IR_NODE_MODE (_result) = node_mode;
  _IR_node_field_initiation (node_mode, _result);
  return _result;
}

IR_node_t IR_new_identifier
(position_t position,
 string_t identifier_itself,
 IR_node_t next_identifier)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_identifier);
  (((_IR_identifier *) _result)->_IR_S_identifier._IR_M_node.position) = position;
  (((_IR_identifier *) _result)->_IR_S_identifier.identifier_itself) = identifier_itself;
  (((_IR_identifier *) _result)->_IR_S_identifier.next_identifier) = next_identifier;
  return _result;
}

IR_node_t IR_new_code_insertion
(position_t position,
 string_t code_insertion_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_code_insertion);
  (((_IR_code_insertion *) _result)->_IR_S_code_insertion._IR_M_node.position) = position;
  (((_IR_code_insertion *) _result)->_IR_S_code_insertion.code_insertion_itself) = code_insertion_itself;
  return _result;
}

IR_node_t IR_new_expression
(position_t position,
 string_t expression_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_expression);
  (((_IR_expression *) _result)->_IR_S_expression._IR_M_node.position) = position;
  (((_IR_expression *) _result)->_IR_S_expression.expression_itself) = expression_itself;
  return _result;
}

IR_node_t IR_new_term_declaration
(position_t position,
 IR_node_t next_declaration,
 IR_node_t identifier_list,
 IR_node_t type)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_term_declaration);
  (((_IR_term_declaration *) _result)->_IR_S_term_declaration._IR_M_identifier_declaration._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_term_declaration *) _result)->_IR_S_term_declaration._IR_M_identifier_declaration._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_term_declaration *) _result)->_IR_S_term_declaration._IR_M_identifier_declaration.identifier_list) = identifier_list;
  (((_IR_term_declaration *) _result)->_IR_S_term_declaration._IR_M_identifier_declaration.type) = type;
  return _result;
}

IR_node_t IR_new_commutative_declaration
(position_t position,
 IR_node_t next_declaration,
 IR_node_t identifier_list,
 IR_node_t type)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_commutative_declaration);
  (((_IR_commutative_declaration *) _result)->_IR_S_commutative_declaration._IR_M_identifier_declaration._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_commutative_declaration *) _result)->_IR_S_commutative_declaration._IR_M_identifier_declaration._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_commutative_declaration *) _result)->_IR_S_commutative_declaration._IR_M_identifier_declaration.identifier_list) = identifier_list;
  (((_IR_commutative_declaration *) _result)->_IR_S_commutative_declaration._IR_M_identifier_declaration.type) = type;
  return _result;
}

IR_node_t IR_new_type_declaration
(position_t position,
 IR_node_t next_declaration,
 IR_node_t identifier_list,
 IR_node_t type)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_type_declaration);
  (((_IR_type_declaration *) _result)->_IR_S_type_declaration._IR_M_identifier_declaration._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_type_declaration *) _result)->_IR_S_type_declaration._IR_M_identifier_declaration._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_type_declaration *) _result)->_IR_S_type_declaration._IR_M_identifier_declaration.identifier_list) = identifier_list;
  (((_IR_type_declaration *) _result)->_IR_S_type_declaration._IR_M_identifier_declaration.type) = type;
  return _result;
}

IR_node_t IR_new_local_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_local_code);
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_import_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_import_code);
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_export_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_export_code);
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_union_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_union_code);
  (((_IR_union_code *) _result)->_IR_S_union_code._IR_M_code._IR_M_declaration._IR_M_node.position) = position;
  (((_IR_union_code *) _result)->_IR_S_union_code._IR_M_code._IR_M_declaration.next_declaration) = next_declaration;
  (((_IR_union_code *) _result)->_IR_S_union_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_rule
(position_t position,
 IR_node_t nonterm_identifier,
 IR_node_t pattern,
 IR_node_t optional_cost,
 IR_node_t optional_constraint,
 IR_node_t optional_action,
 IR_node_t next_rule)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_rule);
  (((_IR_rule *) _result)->_IR_S_rule._IR_M_node.position) = position;
  (((_IR_rule *) _result)->_IR_S_rule.nonterm_identifier) = nonterm_identifier;
  (((_IR_rule *) _result)->_IR_S_rule.pattern) = pattern;
  (((_IR_rule *) _result)->_IR_S_rule.optional_cost) = optional_cost;
  (((_IR_rule *) _result)->_IR_S_rule.optional_constraint) = optional_constraint;
  (((_IR_rule *) _result)->_IR_S_rule.optional_action) = optional_action;
  (((_IR_rule *) _result)->_IR_S_rule.next_rule) = next_rule;
  return _result;
}

IR_node_t IR_new_pattern
(position_t position,
 IR_node_t identifier,
 IR_node_t pattern_list,
 IR_node_t next_pattern)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_pattern);
  (((_IR_pattern *) _result)->_IR_S_pattern._IR_M_node.position) = position;
  (((_IR_pattern *) _result)->_IR_S_pattern.identifier) = identifier;
  (((_IR_pattern *) _result)->_IR_S_pattern.pattern_list) = pattern_list;
  (((_IR_pattern *) _result)->_IR_S_pattern.next_pattern) = next_pattern;
  return _result;
}

IR_node_t IR_new_additional_code
(position_t position,
 string_t additional_code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_additional_code);
  (((_IR_additional_code *) _result)->_IR_S_additional_code._IR_M_node.position) = position;
  (((_IR_additional_code *) _result)->_IR_S_additional_code.additional_code_itself) = additional_code_itself;
  return _result;
}

IR_node_t IR_new_description
(position_t position,
 IR_node_t declaration_list,
 IR_node_t rule_list,
 IR_node_t additional_code)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_description);
  (((_IR_description *) _result)->_IR_S_description._IR_M_node.position) = position;
  (((_IR_description *) _result)->_IR_S_description.declaration_list) = declaration_list;
  (((_IR_description *) _result)->_IR_S_description.rule_list) = rule_list;
  (((_IR_description *) _result)->_IR_S_description.additional_code) = additional_code;
  return _result;
}

IR_node_t IR_new_single_term_declaration
(position_t position,
 IR_node_t identifier,
 IR_node_t next_single_declaration,
 IR_node_t type,
 bool_t commutative_flag,
 position_t first_position_in_rules,
 IR_node_t term_rule_list,
 integer_t arity)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_single_term_declaration);
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration._IR_M_single_declaration._IR_M_node.position) = position;
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration._IR_M_single_declaration.identifier) = identifier;
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration._IR_M_single_declaration.next_single_declaration) = next_single_declaration;
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration._IR_M_single_declaration.type) = type;
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration.commutative_flag) = commutative_flag;
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration.first_position_in_rules) = first_position_in_rules;
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration.term_rule_list) = term_rule_list;
  (((_IR_single_term_declaration *) _result)->_IR_S_single_term_declaration.arity) = arity;
  return _result;
}

IR_node_t IR_new_single_nonterm_declaration
(position_t position,
 IR_node_t identifier,
 IR_node_t next_single_declaration,
 IR_node_t type,
 integer_t number_of_nonterminal_rules,
 IR_node_t nonterm_rule_list,
 IR_node_t chain_rule_list,
 bool_t derivability_flag,
 integer_t traverse_number)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_single_nonterm_declaration);
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration._IR_M_single_declaration._IR_M_node.position) = position;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration._IR_M_single_declaration.identifier) = identifier;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration._IR_M_single_declaration.next_single_declaration) = next_single_declaration;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration._IR_M_single_declaration.type) = type;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration.number_of_nonterminal_rules) = number_of_nonterminal_rules;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration.nonterm_rule_list) = nonterm_rule_list;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration.chain_rule_list) = chain_rule_list;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration.derivability_flag) = derivability_flag;
  (((_IR_single_nonterm_declaration *) _result)->_IR_S_single_nonterm_declaration.traverse_number) = traverse_number;
  return _result;
}

static void _IR_copy_node_fields (IR_node_mode_t node_mode, IR_node_t to, IR_node_t from)
{
  switch (node_mode)
    {
    case IR_NM_node:
      IR_COPY_position_t ((((_IR_node *) to)->_IR_S_node.position), (((_IR_node *) from)->_IR_S_node.position));
      break;
    case IR_NM_identifier:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_identifier *) to)->_IR_S_identifier._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_identifier *) from)->_IR_S_identifier._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_string_t ((((_IR_identifier *) to)->_IR_S_identifier.identifier_itself), (((_IR_identifier *) from)->_IR_S_identifier.identifier_itself));
      IR_COPY_IR_node_t ((((_IR_identifier *) to)->_IR_S_identifier.next_identifier), (((_IR_identifier *) from)->_IR_S_identifier.next_identifier));
      break;
    case IR_NM_code_insertion:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_code_insertion *) to)->_IR_S_code_insertion._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_code_insertion *) from)->_IR_S_code_insertion._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_string_t ((((_IR_code_insertion *) to)->_IR_S_code_insertion.code_insertion_itself), (((_IR_code_insertion *) from)->_IR_S_code_insertion.code_insertion_itself));
      break;
    case IR_NM_expression:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_expression *) to)->_IR_S_expression._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_expression *) from)->_IR_S_expression._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_string_t ((((_IR_expression *) to)->_IR_S_expression.expression_itself), (((_IR_expression *) from)->_IR_S_expression.expression_itself));
      break;
    case IR_NM_declaration:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_declaration *) to)->_IR_S_declaration._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_declaration *) from)->_IR_S_declaration._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_declaration *) to)->_IR_S_declaration.next_declaration), (((_IR_declaration *) from)->_IR_S_declaration.next_declaration));
      break;
    case IR_NM_identifier_declaration:
      _IR_copy_node_fields (IR_NM_declaration, (IR_node_t) ((char *) &((_IR_identifier_declaration *) to)->_IR_S_identifier_declaration._IR_M_declaration - _IR_offsetof (_IR_declaration, _IR_S_declaration)), (IR_node_t) ((char *) &((_IR_identifier_declaration *) from)->_IR_S_identifier_declaration._IR_M_declaration - _IR_offsetof (_IR_declaration, _IR_S_declaration)));
      IR_COPY_IR_node_t ((((_IR_identifier_declaration *) to)->_IR_S_identifier_declaration.identifier_list), (((_IR_identifier_declaration *) from)->_IR_S_identifier_declaration.identifier_list));
      IR_COPY_IR_node_t ((((_IR_identifier_declaration *) to)->_IR_S_identifier_declaration.type), (((_IR_identifier_declaration *) from)->_IR_S_identifier_declaration.type));
      break;
    case IR_NM_term_declaration:
      _IR_copy_node_fields (IR_NM_identifier_declaration, (IR_node_t) ((char *) &((_IR_term_declaration *) to)->_IR_S_term_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)), (IR_node_t) ((char *) &((_IR_term_declaration *) from)->_IR_S_term_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)));
      break;
    case IR_NM_commutative_declaration:
      _IR_copy_node_fields (IR_NM_identifier_declaration, (IR_node_t) ((char *) &((_IR_commutative_declaration *) to)->_IR_S_commutative_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)), (IR_node_t) ((char *) &((_IR_commutative_declaration *) from)->_IR_S_commutative_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)));
      break;
    case IR_NM_type_declaration:
      _IR_copy_node_fields (IR_NM_identifier_declaration, (IR_node_t) ((char *) &((_IR_type_declaration *) to)->_IR_S_type_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)), (IR_node_t) ((char *) &((_IR_type_declaration *) from)->_IR_S_type_declaration._IR_M_identifier_declaration - _IR_offsetof (_IR_identifier_declaration, _IR_S_identifier_declaration)));
      break;
    case IR_NM_code:
      _IR_copy_node_fields (IR_NM_declaration, (IR_node_t) ((char *) &((_IR_code *) to)->_IR_S_code._IR_M_declaration - _IR_offsetof (_IR_declaration, _IR_S_declaration)), (IR_node_t) ((char *) &((_IR_code *) from)->_IR_S_code._IR_M_declaration - _IR_offsetof (_IR_declaration, _IR_S_declaration)));
      IR_COPY_IR_node_t ((((_IR_code *) to)->_IR_S_code.code_itself), (((_IR_code *) from)->_IR_S_code.code_itself));
      break;
    case IR_NM_local_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_local_code *) to)->_IR_S_local_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_local_code *) from)->_IR_S_local_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_import_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_import_code *) to)->_IR_S_import_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_import_code *) from)->_IR_S_import_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_export_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_export_code *) to)->_IR_S_export_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_export_code *) from)->_IR_S_export_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_union_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_union_code *) to)->_IR_S_union_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_union_code *) from)->_IR_S_union_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_rule:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_rule *) to)->_IR_S_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_rule *) from)->_IR_S_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.nonterm_identifier), (((_IR_rule *) from)->_IR_S_rule.nonterm_identifier));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.pattern), (((_IR_rule *) from)->_IR_S_rule.pattern));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.optional_cost), (((_IR_rule *) from)->_IR_S_rule.optional_cost));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.optional_constraint), (((_IR_rule *) from)->_IR_S_rule.optional_constraint));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.optional_action), (((_IR_rule *) from)->_IR_S_rule.optional_action));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.next_rule), (((_IR_rule *) from)->_IR_S_rule.next_rule));
      IR_COPY_bool_t ((((_IR_rule *) to)->_IR_S_rule.new_commutative_rule_flag), (((_IR_rule *) from)->_IR_S_rule.new_commutative_rule_flag));
      IR_COPY_integer_t ((((_IR_rule *) to)->_IR_S_rule.rule_number), (((_IR_rule *) from)->_IR_S_rule.rule_number));
      IR_COPY_integer_t ((((_IR_rule *) to)->_IR_S_rule.nonterm_rule_number), (((_IR_rule *) from)->_IR_S_rule.nonterm_rule_number));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.next_nonterm_rule), (((_IR_rule *) from)->_IR_S_rule.next_nonterm_rule));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.next_chain_rule), (((_IR_rule *) from)->_IR_S_rule.next_chain_rule));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.textual_pattern_list), (((_IR_rule *) from)->_IR_S_rule.textual_pattern_list));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.single_nonterm_declaration), (((_IR_rule *) from)->_IR_S_rule.single_nonterm_declaration));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.next_term_rule), (((_IR_rule *) from)->_IR_S_rule.next_term_rule));
      break;
    case IR_NM_pattern:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_pattern *) to)->_IR_S_pattern._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_pattern *) from)->_IR_S_pattern._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_pattern *) to)->_IR_S_pattern.identifier), (((_IR_pattern *) from)->_IR_S_pattern.identifier));
      IR_COPY_IR_node_t ((((_IR_pattern *) to)->_IR_S_pattern.pattern_list), (((_IR_pattern *) from)->_IR_S_pattern.pattern_list));
      IR_COPY_IR_node_t ((((_IR_pattern *) to)->_IR_S_pattern.next_pattern), (((_IR_pattern *) from)->_IR_S_pattern.next_pattern));
      IR_COPY_integer_t ((((_IR_pattern *) to)->_IR_S_pattern.original_number), (((_IR_pattern *) from)->_IR_S_pattern.original_number));
      IR_COPY_bool_t ((((_IR_pattern *) to)->_IR_S_pattern.commutative_process_flag), (((_IR_pattern *) from)->_IR_S_pattern.commutative_process_flag));
      IR_COPY_IR_node_t ((((_IR_pattern *) to)->_IR_S_pattern.single_declaration), (((_IR_pattern *) from)->_IR_S_pattern.single_declaration));
      IR_COPY_IR_node_t ((((_IR_pattern *) to)->_IR_S_pattern.next_textual_pattern), (((_IR_pattern *) from)->_IR_S_pattern.next_textual_pattern));
      IR_COPY_integer_t ((((_IR_pattern *) to)->_IR_S_pattern.textual_nonterminal_pattern_number), (((_IR_pattern *) from)->_IR_S_pattern.textual_nonterminal_pattern_number));
      IR_COPY_IR_node_t ((((_IR_pattern *) to)->_IR_S_pattern.father), (((_IR_pattern *) from)->_IR_S_pattern.father));
      break;
    case IR_NM_additional_code:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_additional_code *) to)->_IR_S_additional_code._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_additional_code *) from)->_IR_S_additional_code._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_string_t ((((_IR_additional_code *) to)->_IR_S_additional_code.additional_code_itself), (((_IR_additional_code *) from)->_IR_S_additional_code.additional_code_itself));
      break;
    case IR_NM_description:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_description *) to)->_IR_S_description._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_description *) from)->_IR_S_description._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.declaration_list), (((_IR_description *) from)->_IR_S_description.declaration_list));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.rule_list), (((_IR_description *) from)->_IR_S_description.rule_list));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.additional_code), (((_IR_description *) from)->_IR_S_description.additional_code));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.single_declaration_list), (((_IR_description *) from)->_IR_S_description.single_declaration_list));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.number_of_nonterminals), (((_IR_description *) from)->_IR_S_description.number_of_nonterminals));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.max_number_of_rule_nonterminals), (((_IR_description *) from)->_IR_S_description.max_number_of_rule_nonterminals));
      break;
    case IR_NM_single_declaration:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_single_declaration *) to)->_IR_S_single_declaration._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_single_declaration *) from)->_IR_S_single_declaration._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_single_declaration *) to)->_IR_S_single_declaration.identifier), (((_IR_single_declaration *) from)->_IR_S_single_declaration.identifier));
      IR_COPY_IR_node_t ((((_IR_single_declaration *) to)->_IR_S_single_declaration.next_single_declaration), (((_IR_single_declaration *) from)->_IR_S_single_declaration.next_single_declaration));
      IR_COPY_IR_node_t ((((_IR_single_declaration *) to)->_IR_S_single_declaration.type), (((_IR_single_declaration *) from)->_IR_S_single_declaration.type));
      break;
    case IR_NM_single_term_declaration:
      _IR_copy_node_fields (IR_NM_single_declaration, (IR_node_t) ((char *) &((_IR_single_term_declaration *) to)->_IR_S_single_term_declaration._IR_M_single_declaration - _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)), (IR_node_t) ((char *) &((_IR_single_term_declaration *) from)->_IR_S_single_term_declaration._IR_M_single_declaration - _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)));
      IR_COPY_bool_t ((((_IR_single_term_declaration *) to)->_IR_S_single_term_declaration.commutative_flag), (((_IR_single_term_declaration *) from)->_IR_S_single_term_declaration.commutative_flag));
      IR_COPY_position_t ((((_IR_single_term_declaration *) to)->_IR_S_single_term_declaration.first_position_in_rules), (((_IR_single_term_declaration *) from)->_IR_S_single_term_declaration.first_position_in_rules));
      IR_COPY_IR_node_t ((((_IR_single_term_declaration *) to)->_IR_S_single_term_declaration.term_rule_list), (((_IR_single_term_declaration *) from)->_IR_S_single_term_declaration.term_rule_list));
      IR_COPY_integer_t ((((_IR_single_term_declaration *) to)->_IR_S_single_term_declaration.arity), (((_IR_single_term_declaration *) from)->_IR_S_single_term_declaration.arity));
      break;
    case IR_NM_single_nonterm_declaration:
      _IR_copy_node_fields (IR_NM_single_declaration, (IR_node_t) ((char *) &((_IR_single_nonterm_declaration *) to)->_IR_S_single_nonterm_declaration._IR_M_single_declaration - _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)), (IR_node_t) ((char *) &((_IR_single_nonterm_declaration *) from)->_IR_S_single_nonterm_declaration._IR_M_single_declaration - _IR_offsetof (_IR_single_declaration, _IR_S_single_declaration)));
      IR_COPY_integer_t ((((_IR_single_nonterm_declaration *) to)->_IR_S_single_nonterm_declaration.number_of_nonterminal_rules), (((_IR_single_nonterm_declaration *) from)->_IR_S_single_nonterm_declaration.number_of_nonterminal_rules));
      IR_COPY_IR_node_t ((((_IR_single_nonterm_declaration *) to)->_IR_S_single_nonterm_declaration.nonterm_rule_list), (((_IR_single_nonterm_declaration *) from)->_IR_S_single_nonterm_declaration.nonterm_rule_list));
      IR_COPY_IR_node_t ((((_IR_single_nonterm_declaration *) to)->_IR_S_single_nonterm_declaration.chain_rule_list), (((_IR_single_nonterm_declaration *) from)->_IR_S_single_nonterm_declaration.chain_rule_list));
      IR_COPY_bool_t ((((_IR_single_nonterm_declaration *) to)->_IR_S_single_nonterm_declaration.derivability_flag), (((_IR_single_nonterm_declaration *) from)->_IR_S_single_nonterm_declaration.derivability_flag));
      IR_COPY_integer_t ((((_IR_single_nonterm_declaration *) to)->_IR_S_single_nonterm_declaration.traverse_number), (((_IR_single_nonterm_declaration *) from)->_IR_S_single_nonterm_declaration.traverse_number));
      break;
    default:
      abort ();
      break;
    }
}

IR_node_t IR_copy_node (IR_node_t node)
{
  IR_node_t _result;

  if (node == NULL)
    return NULL;
  IR_ALLOC (_result, IR_node_size [IR_NODE_MODE (node)], IR_node_t);
#ifdef __IR_DEBUG__
  if (_result == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  IR_NODE_MODE (_result) = IR_NODE_MODE (node);
  _IR_copy_node_fields (IR_NODE_MODE (node), _result, node);
  return _result;
}

void IR_start (void)
{
#ifdef __IR_DEBUG__
  if (sizeof (_IR_node) > 255)
    {
      fprintf (stderr, "Very long node `node' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_identifier) > 255)
    {
      fprintf (stderr, "Very long node `identifier' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_code_insertion) > 255)
    {
      fprintf (stderr, "Very long node `code_insertion' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_expression) > 255)
    {
      fprintf (stderr, "Very long node `expression' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_declaration) > 255)
    {
      fprintf (stderr, "Very long node `declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_identifier_declaration) > 255)
    {
      fprintf (stderr, "Very long node `identifier_declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_term_declaration) > 255)
    {
      fprintf (stderr, "Very long node `term_declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_commutative_declaration) > 255)
    {
      fprintf (stderr, "Very long node `commutative_declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_type_declaration) > 255)
    {
      fprintf (stderr, "Very long node `type_declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_code) > 255)
    {
      fprintf (stderr, "Very long node `code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_local_code) > 255)
    {
      fprintf (stderr, "Very long node `local_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_import_code) > 255)
    {
      fprintf (stderr, "Very long node `import_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_export_code) > 255)
    {
      fprintf (stderr, "Very long node `export_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_union_code) > 255)
    {
      fprintf (stderr, "Very long node `union_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_rule) > 255)
    {
      fprintf (stderr, "Very long node `rule' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_pattern) > 255)
    {
      fprintf (stderr, "Very long node `pattern' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_additional_code) > 255)
    {
      fprintf (stderr, "Very long node `additional_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_description) > 255)
    {
      fprintf (stderr, "Very long node `description' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_single_declaration) > 255)
    {
      fprintf (stderr, "Very long node `single_declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_single_term_declaration) > 255)
    {
      fprintf (stderr, "Very long node `single_term_declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_single_nonterm_declaration) > 255)
    {
      fprintf (stderr, "Very long node `single_nonterm_declaration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
  _IR_current_graph_pass_number = 0;
  IR_START_ALLOC ();
}

void IR_stop (void)
{
  IR_STOP_ALLOC ();
}



#line 419 "./ird.sprut"
