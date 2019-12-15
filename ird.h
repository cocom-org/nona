#ifndef __IR_ird__
#define __IR_ird__

#define _IR_offsetof(type, field) ((char *)&((type *) 64)->field - (char *) 64)


#line 38 "./ird.sprut"


#include "objstack.h"
#include "position.h"

/* Definitions of predefined types: */

typedef int integer_t;

typedef int bool_t;

typedef char *string_t;



#line 24 "ird.h"

typedef enum IR_node_mode_enum
{
  IR_NM_node,
  IR_NM_identifier,
  IR_NM_code_insertion,
  IR_NM_expression,
  IR_NM_declaration,
  IR_NM_identifier_declaration,
  IR_NM_term_declaration,
  IR_NM_commutative_declaration,
  IR_NM_type_declaration,
  IR_NM_code,
  IR_NM_local_code,
  IR_NM_import_code,
  IR_NM_export_code,
  IR_NM_union_code,
  IR_NM_rule,
  IR_NM_pattern,
  IR_NM_additional_code,
  IR_NM_description,
  IR_NM_single_declaration,
  IR_NM_single_term_declaration,
  IR_NM_single_nonterm_declaration,
  IR_NM__root,
  IR_NM__error
} IR_node_mode_t;

extern short _IR_node_level [];

extern unsigned char _IR_SF_node [];

extern unsigned char _IR_SF_identifier [];

extern unsigned char _IR_SF_code_insertion [];

extern unsigned char _IR_SF_expression [];

extern unsigned char _IR_SF_declaration [];

extern unsigned char _IR_SF_identifier_declaration [];

extern unsigned char _IR_SF_term_declaration [];

extern unsigned char _IR_SF_commutative_declaration [];

extern unsigned char _IR_SF_type_declaration [];

extern unsigned char _IR_SF_code [];

extern unsigned char _IR_SF_local_code [];

extern unsigned char _IR_SF_import_code [];

extern unsigned char _IR_SF_export_code [];

extern unsigned char _IR_SF_union_code [];

extern unsigned char _IR_SF_rule [];

extern unsigned char _IR_SF_pattern [];

extern unsigned char _IR_SF_additional_code [];

extern unsigned char _IR_SF_description [];

extern unsigned char _IR_SF_single_declaration [];

extern unsigned char _IR_SF_single_term_declaration [];

extern unsigned char _IR_SF_single_nonterm_declaration [];

extern unsigned char _IR_SF__root [];

extern unsigned char _IR_SF__error [];

extern unsigned char *_IR_is_type[];

extern unsigned char _IR_D_type [];

extern unsigned char _IR_D_identifier [];

extern void *_IR_class_structure_array [];

typedef struct IR_node *IR_node_t;

typedef struct _IR_double_link *IR_double_link_t;

struct _IR_double_link
{
  IR_node_t field_itself;
  IR_node_t link_owner;
  void (*set_function) (IR_node_t, IR_node_t);
  IR_double_link_t previous_link;
  IR_double_link_t next_link;
};

struct _IR_S_node
{
  position_t  position;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_node _IR_S_node;
} _IR_node;

struct _IR_S_identifier
{
  struct _IR_S_node _IR_M_node;
  string_t  identifier_itself;
  IR_node_t  next_identifier;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_identifier _IR_S_identifier;
} _IR_identifier;

struct _IR_S_code_insertion
{
  struct _IR_S_node _IR_M_node;
  string_t  code_insertion_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_code_insertion _IR_S_code_insertion;
} _IR_code_insertion;

struct _IR_S_expression
{
  struct _IR_S_node _IR_M_node;
  string_t  expression_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_expression _IR_S_expression;
} _IR_expression;

struct _IR_S_declaration
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  next_declaration;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_declaration _IR_S_declaration;
} _IR_declaration;

struct _IR_S_identifier_declaration
{
  struct _IR_S_declaration _IR_M_declaration;
  IR_node_t  identifier_list;
  IR_node_t  type;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_identifier_declaration _IR_S_identifier_declaration;
} _IR_identifier_declaration;

struct _IR_S_term_declaration
{
  struct _IR_S_identifier_declaration _IR_M_identifier_declaration;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_term_declaration _IR_S_term_declaration;
} _IR_term_declaration;

struct _IR_S_commutative_declaration
{
  struct _IR_S_identifier_declaration _IR_M_identifier_declaration;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_commutative_declaration _IR_S_commutative_declaration;
} _IR_commutative_declaration;

struct _IR_S_type_declaration
{
  struct _IR_S_identifier_declaration _IR_M_identifier_declaration;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_type_declaration _IR_S_type_declaration;
} _IR_type_declaration;

struct _IR_S_code
{
  struct _IR_S_declaration _IR_M_declaration;
  IR_node_t  code_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_code _IR_S_code;
} _IR_code;

struct _IR_S_local_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_local_code _IR_S_local_code;
} _IR_local_code;

struct _IR_S_import_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_import_code _IR_S_import_code;
} _IR_import_code;

struct _IR_S_export_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_export_code _IR_S_export_code;
} _IR_export_code;

struct _IR_S_union_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_union_code _IR_S_union_code;
} _IR_union_code;

struct _IR_S_rule
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  nonterm_identifier;
  IR_node_t  pattern;
  IR_node_t  optional_cost;
  IR_node_t  optional_constraint;
  IR_node_t  optional_action;
  IR_node_t  next_rule;
  bool_t  new_commutative_rule_flag;
  integer_t  rule_number;
  integer_t  nonterm_rule_number;
  IR_node_t  next_nonterm_rule;
  IR_node_t  next_chain_rule;
  IR_node_t  textual_pattern_list;
  IR_node_t  single_nonterm_declaration;
  IR_node_t  next_term_rule;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_rule _IR_S_rule;
} _IR_rule;

struct _IR_S_pattern
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  identifier;
  IR_node_t  pattern_list;
  IR_node_t  next_pattern;
  integer_t  original_number;
  bool_t  commutative_process_flag;
  IR_node_t  single_declaration;
  IR_node_t  next_textual_pattern;
  integer_t  textual_nonterminal_pattern_number;
  IR_node_t  father;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_pattern _IR_S_pattern;
} _IR_pattern;

struct _IR_S_additional_code
{
  struct _IR_S_node _IR_M_node;
  string_t  additional_code_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_additional_code _IR_S_additional_code;
} _IR_additional_code;

struct _IR_S_description
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  declaration_list;
  IR_node_t  rule_list;
  IR_node_t  additional_code;
  IR_node_t  single_declaration_list;
  integer_t  number_of_nonterminals;
  integer_t  max_number_of_rule_nonterminals;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_description _IR_S_description;
} _IR_description;

struct _IR_S_single_declaration
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  identifier;
  IR_node_t  next_single_declaration;
  IR_node_t  type;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_single_declaration _IR_S_single_declaration;
} _IR_single_declaration;

struct _IR_S_single_term_declaration
{
  struct _IR_S_single_declaration _IR_M_single_declaration;
  bool_t  commutative_flag;
  position_t  first_position_in_rules;
  IR_node_t  term_rule_list;
  integer_t  arity;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_single_term_declaration _IR_S_single_term_declaration;
} _IR_single_term_declaration;

struct _IR_S_single_nonterm_declaration
{
  struct _IR_S_single_declaration _IR_M_single_declaration;
  integer_t  number_of_nonterminal_rules;
  IR_node_t  nonterm_rule_list;
  IR_node_t  chain_rule_list;
  bool_t  derivability_flag;
  integer_t  traverse_number;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  struct _IR_S_single_nonterm_declaration _IR_S_single_nonterm_declaration;
} _IR_single_nonterm_declaration;

typedef struct IR_node
{
  IR_node_mode_t _IR_node_mode;
} _IR__root;

typedef struct
{
  IR_node_mode_t _IR_node_mode;
} _IR__error;

#define IR_NODE_MODE(t) ((t)->_IR_node_mode)

extern const char *IR_node_name[];

extern unsigned char IR_node_size[];

#define IR_NODE_LEVEL(node) _IR_node_level [IR_NODE_MODE (node)]

#define IR_IS_TYPE(type, super) ((_IR_is_type [super] [type /8] >> (type % 8)) & 1)

#define IR_IS_OF_TYPE(node, super)IR_IS_TYPE (IR_NODE_MODE (node), super)

extern void _IR_set_double_field_value
  (IR_double_link_t link, IR_node_t value, int disp, int flag);

extern IR_double_link_t IR__first_double_link (IR_node_t node);

#define IR__next_double_link(prev_double_link) ((prev_double_link)->next_link)

#define IR__previous_double_link(next_double_link) ((next_double_link)->previous_link)

#define IR__owner(link) ((link)->link_owner)

#define IR_position(_node) (((_IR_node *) (_node))->_IR_S_node.position)

#define IR_identifier_itself(_node) (((_IR_identifier *) (_node))->_IR_S_identifier.identifier_itself)

#define IR_next_identifier(_node) (((_IR_identifier *) (_node))->_IR_S_identifier.next_identifier)

#define IR_code_insertion_itself(_node) (((_IR_code_insertion *) (_node))->_IR_S_code_insertion.code_insertion_itself)

#define IR_expression_itself(_node) (((_IR_expression *) (_node))->_IR_S_expression.expression_itself)

#define IR_next_declaration(_node) (((_IR_declaration *) (_node))->_IR_S_declaration.next_declaration)

#define IR_identifier_list(_node) (((_IR_identifier_declaration *) (_node))->_IR_S_identifier_declaration.identifier_list)

#define IR_type(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_type [IR_NODE_MODE ((_node))]))

#define IR_code_itself(_node) (((_IR_code *) (_node))->_IR_S_code.code_itself)

#define IR_nonterm_identifier(_node) (((_IR_rule *) (_node))->_IR_S_rule.nonterm_identifier)

#define IR_pattern(_node) (((_IR_rule *) (_node))->_IR_S_rule.pattern)

#define IR_optional_cost(_node) (((_IR_rule *) (_node))->_IR_S_rule.optional_cost)

#define IR_optional_constraint(_node) (((_IR_rule *) (_node))->_IR_S_rule.optional_constraint)

#define IR_optional_action(_node) (((_IR_rule *) (_node))->_IR_S_rule.optional_action)

#define IR_next_rule(_node) (((_IR_rule *) (_node))->_IR_S_rule.next_rule)

#define IR_new_commutative_rule_flag(_node) (((_IR_rule *) (_node))->_IR_S_rule.new_commutative_rule_flag)

#define IR_rule_number(_node) (((_IR_rule *) (_node))->_IR_S_rule.rule_number)

#define IR_nonterm_rule_number(_node) (((_IR_rule *) (_node))->_IR_S_rule.nonterm_rule_number)

#define IR_next_nonterm_rule(_node) (((_IR_rule *) (_node))->_IR_S_rule.next_nonterm_rule)

#define IR_next_chain_rule(_node) (((_IR_rule *) (_node))->_IR_S_rule.next_chain_rule)

#define IR_textual_pattern_list(_node) (((_IR_rule *) (_node))->_IR_S_rule.textual_pattern_list)

#define IR_single_nonterm_declaration(_node) (((_IR_rule *) (_node))->_IR_S_rule.single_nonterm_declaration)

#define IR_next_term_rule(_node) (((_IR_rule *) (_node))->_IR_S_rule.next_term_rule)

#define IR_identifier(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_identifier [IR_NODE_MODE ((_node))]))

#define IR_pattern_list(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.pattern_list)

#define IR_next_pattern(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.next_pattern)

#define IR_original_number(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.original_number)

#define IR_commutative_process_flag(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.commutative_process_flag)

#define IR_single_declaration(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.single_declaration)

#define IR_next_textual_pattern(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.next_textual_pattern)

#define IR_textual_nonterminal_pattern_number(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.textual_nonterminal_pattern_number)

#define IR_father(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.father)

#define IR_additional_code_itself(_node) (((_IR_additional_code *) (_node))->_IR_S_additional_code.additional_code_itself)

#define IR_declaration_list(_node) (((_IR_description *) (_node))->_IR_S_description.declaration_list)

#define IR_rule_list(_node) (((_IR_description *) (_node))->_IR_S_description.rule_list)

#define IR_additional_code(_node) (((_IR_description *) (_node))->_IR_S_description.additional_code)

#define IR_single_declaration_list(_node) (((_IR_description *) (_node))->_IR_S_description.single_declaration_list)

#define IR_number_of_nonterminals(_node) (((_IR_description *) (_node))->_IR_S_description.number_of_nonterminals)

#define IR_max_number_of_rule_nonterminals(_node) (((_IR_description *) (_node))->_IR_S_description.max_number_of_rule_nonterminals)

#define IR_next_single_declaration(_node) (((_IR_single_declaration *) (_node))->_IR_S_single_declaration.next_single_declaration)

#define IR_commutative_flag(_node) (((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.commutative_flag)

#define IR_first_position_in_rules(_node) (((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.first_position_in_rules)

#define IR_term_rule_list(_node) (((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.term_rule_list)

#define IR_arity(_node) (((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.arity)

#define IR_number_of_nonterminal_rules(_node) (((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.number_of_nonterminal_rules)

#define IR_nonterm_rule_list(_node) (((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.nonterm_rule_list)

#define IR_chain_rule_list(_node) (((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.chain_rule_list)

#define IR_derivability_flag(_node) (((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.derivability_flag)

#define IR_traverse_number(_node) (((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.traverse_number)

extern void IR__set_double_link (IR_double_link_t link, IR_node_t value);

#define IR_set_position(_node, _value) ((((_IR_node *) (_node))->_IR_S_node.position) = (_value))

#define IR_set_identifier_itself(_node, _value) ((((_IR_identifier *) (_node))->_IR_S_identifier.identifier_itself) = (_value))

#define IR_set_next_identifier(_node, _value) ((((_IR_identifier *) (_node))->_IR_S_identifier.next_identifier) = (_value))

#define IR_set_code_insertion_itself(_node, _value) ((((_IR_code_insertion *) (_node))->_IR_S_code_insertion.code_insertion_itself) = (_value))

#define IR_set_expression_itself(_node, _value) ((((_IR_expression *) (_node))->_IR_S_expression.expression_itself) = (_value))

#define IR_set_next_declaration(_node, _value) ((((_IR_declaration *) (_node))->_IR_S_declaration.next_declaration) = (_value))

#define IR_set_identifier_list(_node, _value) ((((_IR_identifier_declaration *) (_node))->_IR_S_identifier_declaration.identifier_list) = (_value))

#define IR_set_type(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_type [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_code_itself(_node, _value) ((((_IR_code *) (_node))->_IR_S_code.code_itself) = (_value))

#define IR_set_nonterm_identifier(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.nonterm_identifier) = (_value))

#define IR_set_pattern(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.pattern) = (_value))

#define IR_set_optional_cost(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.optional_cost) = (_value))

#define IR_set_optional_constraint(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.optional_constraint) = (_value))

#define IR_set_optional_action(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.optional_action) = (_value))

#define IR_set_next_rule(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.next_rule) = (_value))

#define IR_set_new_commutative_rule_flag(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.new_commutative_rule_flag) = (_value))

#define IR_set_rule_number(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.rule_number) = (_value))

#define IR_set_nonterm_rule_number(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.nonterm_rule_number) = (_value))

#define IR_set_next_nonterm_rule(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.next_nonterm_rule) = (_value))

#define IR_set_next_chain_rule(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.next_chain_rule) = (_value))

#define IR_set_textual_pattern_list(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.textual_pattern_list) = (_value))

#define IR_set_single_nonterm_declaration(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.single_nonterm_declaration) = (_value))

#define IR_set_next_term_rule(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.next_term_rule) = (_value))

#define IR_set_identifier(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_identifier [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_pattern_list(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.pattern_list) = (_value))

#define IR_set_next_pattern(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.next_pattern) = (_value))

#define IR_set_original_number(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.original_number) = (_value))

#define IR_set_commutative_process_flag(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.commutative_process_flag) = (_value))

#define IR_set_single_declaration(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.single_declaration) = (_value))

#define IR_set_next_textual_pattern(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.next_textual_pattern) = (_value))

#define IR_set_textual_nonterminal_pattern_number(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.textual_nonterminal_pattern_number) = (_value))

#define IR_set_father(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.father) = (_value))

#define IR_set_additional_code_itself(_node, _value) ((((_IR_additional_code *) (_node))->_IR_S_additional_code.additional_code_itself) = (_value))

#define IR_set_declaration_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.declaration_list) = (_value))

#define IR_set_rule_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.rule_list) = (_value))

#define IR_set_additional_code(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.additional_code) = (_value))

#define IR_set_single_declaration_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.single_declaration_list) = (_value))

#define IR_set_number_of_nonterminals(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.number_of_nonterminals) = (_value))

#define IR_set_max_number_of_rule_nonterminals(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.max_number_of_rule_nonterminals) = (_value))

#define IR_set_next_single_declaration(_node, _value) ((((_IR_single_declaration *) (_node))->_IR_S_single_declaration.next_single_declaration) = (_value))

#define IR_set_commutative_flag(_node, _value) ((((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.commutative_flag) = (_value))

#define IR_set_first_position_in_rules(_node, _value) ((((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.first_position_in_rules) = (_value))

#define IR_set_term_rule_list(_node, _value) ((((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.term_rule_list) = (_value))

#define IR_set_arity(_node, _value) ((((_IR_single_term_declaration *) (_node))->_IR_S_single_term_declaration.arity) = (_value))

#define IR_set_number_of_nonterminal_rules(_node, _value) ((((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.number_of_nonterminal_rules) = (_value))

#define IR_set_nonterm_rule_list(_node, _value) ((((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.nonterm_rule_list) = (_value))

#define IR_set_chain_rule_list(_node, _value) ((((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.chain_rule_list) = (_value))

#define IR_set_derivability_flag(_node, _value) ((((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.derivability_flag) = (_value))

#define IR_set_traverse_number(_node, _value) ((((_IR_single_nonterm_declaration *) (_node))->_IR_S_single_nonterm_declaration.traverse_number) = (_value))

extern IR_node_t IR_create_node (IR_node_mode_t node_mode);

extern IR_node_t IR_new_identifier
(position_t position,
 string_t identifier_itself,
 IR_node_t next_identifier);

extern IR_node_t IR_new_code_insertion
(position_t position,
 string_t code_insertion_itself);

extern IR_node_t IR_new_expression
(position_t position,
 string_t expression_itself);

extern IR_node_t IR_new_term_declaration
(position_t position,
 IR_node_t next_declaration,
 IR_node_t identifier_list,
 IR_node_t type);

extern IR_node_t IR_new_commutative_declaration
(position_t position,
 IR_node_t next_declaration,
 IR_node_t identifier_list,
 IR_node_t type);

extern IR_node_t IR_new_type_declaration
(position_t position,
 IR_node_t next_declaration,
 IR_node_t identifier_list,
 IR_node_t type);

extern IR_node_t IR_new_local_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself);

extern IR_node_t IR_new_import_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself);

extern IR_node_t IR_new_export_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself);

extern IR_node_t IR_new_union_code
(position_t position,
 IR_node_t next_declaration,
 IR_node_t code_itself);

extern IR_node_t IR_new_rule
(position_t position,
 IR_node_t nonterm_identifier,
 IR_node_t pattern,
 IR_node_t optional_cost,
 IR_node_t optional_constraint,
 IR_node_t optional_action,
 IR_node_t next_rule);

extern IR_node_t IR_new_pattern
(position_t position,
 IR_node_t identifier,
 IR_node_t pattern_list,
 IR_node_t next_pattern);

extern IR_node_t IR_new_additional_code
(position_t position,
 string_t additional_code_itself);

extern IR_node_t IR_new_description
(position_t position,
 IR_node_t declaration_list,
 IR_node_t rule_list,
 IR_node_t additional_code);

extern IR_node_t IR_new_single_term_declaration
(position_t position,
 IR_node_t identifier,
 IR_node_t next_single_declaration,
 IR_node_t type,
 bool_t commutative_flag,
 position_t first_position_in_rules,
 IR_node_t term_rule_list,
 integer_t arity);

extern IR_node_t IR_new_single_nonterm_declaration
(position_t position,
 IR_node_t identifier,
 IR_node_t next_single_declaration,
 IR_node_t type,
 integer_t number_of_nonterminal_rules,
 IR_node_t nonterm_rule_list,
 IR_node_t chain_rule_list,
 bool_t derivability_flag,
 integer_t traverse_number);

extern IR_node_t IR_copy_node (IR_node_t node);

extern void IR_start (void);

extern void IR_stop (void);


#line 54 "./ird.sprut"


/* These macros for storage management of NONA internal representation: */

/* Start work with the storage manager -- see NONA documentation. */

#define IR_START_ALLOC()    OS_CREATE (irp, 0)

/* Finish work with the storage manager -- see NONA documentation. */

#define IR_STOP_ALLOC()     OS_DELETE (irp)

/* Allocate storage for internal representation of given size
   -- see NONA documentation. */

#define IR_ALLOC(ptr, size, ptr_type)\
  do {\
    OS_TOP_EXPAND (irp, size); ptr = (ptr_type) OS_TOP_BEGIN (irp);\
    OS_TOP_FINISH (irp);\
  } while (0);

/* Free storage of internal representation of given size -- see NONA
   documentation. */

#define IR_FREE(ptr, size)


/* These macros are analogous to ones of package `object-stack'
   worked with storage of NONA internal representation: */

/* Start new internal representation object -- see also package
   `object-stack'. */

#define IR_TOP_FINISH()  OS_TOP_FINISH (irp)

/* Nullify current internal representation object -- see also package
   `object-stack'. */

#define IR_TOP_NULLIFY()  OS_TOP_NULLIFY (irp)

/* Shorten current internal representation object on given number bytes -- see
   also package `object-stack'. */

#define IR_TOP_SHORTEN(length) OS_TOP_SHORTEN (irp, length)

/* Return start address of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_BEGIN()  OS_TOP_BEGIN (irp)

/* Return length of current internal representation object in bytes -- see
   also package `object-stack'. */

#define IR_TOP_LENGTH()  OS_TOP_LENGTH (irp)

/* Add byte to the end of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_ADD_BYTE(b)  OS_TOP_ADD_BYTE (irp, b)

/* Add string to the end of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_ADD_STRING(str)  OS_TOP_ADD_STRING (irp, str)

/* Add memory of given length to the end of current internal representation
   object -- see also package `object-stack'. */

#define IR_TOP_ADD_MEMORY(mem, length)  OS_TOP_ADD_MEMORY (irp, mem, length)

extern os_t irp;



#line 815 "ird.h"
#endif /* __IR_ird__ */
