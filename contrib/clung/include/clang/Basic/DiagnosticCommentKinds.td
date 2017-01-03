//==--- DiagnosticCommentKinds.td - diagnostics related to comments -------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

let Component = "Comment" in {
let CategoryName = "Documentation Issue" in {

// Commands

def warn_doc_block_command_empty_paragraph : Warning<
  "empty paragraph passed to '%select{\\|@}0%1' command">,
  InGroup<Documentation>, DefaultIgnore;

def warn_doc_block_command_duplicate : Warning<
  "duplicated command '%select{\\|@}0%1'">,
  InGroup<Documentation>, DefaultIgnore;

def note_doc_block_command_previous : Note<
  "previous command '%select{\\|@}0%1' here">;

def note_doc_block_command_previous_alias : Note<
  "previous command '%select{\\|@}0%1' (an alias of '\\%2') here">;

// \param command

def warn_doc_param_invalid_direction : Warning<
  "unrecognized parameter passing direction, "
  "valid directions are '[in]', '[out]' and '[in,out]'">,
  InGroup<Documentation>, DefaultIgnore;

def warn_doc_param_spaces_in_direction : Warning<
  "whitespace is not allowed in parameter passing direction">,
  InGroup<DocumentationPedantic>, DefaultIgnore;

def warn_doc_param_not_attached_to_a_function_decl : Warning<
  "'%select{\\|@}0param' command used in a comment that is not attached to "
  "a function declaration">,
  InGroup<Documentation>, DefaultIgnore;

def warn_doc_function_method_decl_mismatch : Warning<
  "'%select{\\|@}0%select{function|functiongroup|method|methodgroup|callback}1' "
  "command should be used in a comment attached to "
  "%select{a function|a function|an Objective-C method|an Objective-C method|"
  "a pointer to function}2 declaration">,
  InGroup<Documentation>, DefaultIgnore;
  
def warn_doc_api_container_decl_mismatch : Warning<
  "'%select{\\|@}0%select{class|interface|protocol|struct|union}1' "
  "command should not be used in a comment attached to a "
  "non-%select{class|interface|protocol|struct|union}2 declaration">,
  InGroup<Documentation>, DefaultIgnore;
  
def warn_doc_container_decl_mismatch : Warning<
  "'%select{\\|@}0%select{classdesign|coclass|dependency|helper"
  "|helperclass|helps|instancesize|ownership|performance|security|superclass}1' "
  "command should not be used in a comment attached to a non-container declaration">,
  InGroup<Documentation>, DefaultIgnore;
  
def warn_doc_param_duplicate : Warning<
  "parameter '%0' is already documented">,
  InGroup<Documentation>, DefaultIgnore;

def note_doc_param_previous : Note<
  "previous documentation">;

def warn_doc_param_not_found : Warning<
  "parameter '%0' not found in the function declaration">,
  InGroup<Documentation>, DefaultIgnore;

def note_doc_param_name_suggestion : Note<
  "did you mean '%0'?">;

// tparam command

def warn_doc_tparam_not_attached_to_a_template_decl : Warning<
  "'%select{\\|@}0tparam' command used in a comment that is not attached to "
  "a template declaration">,
  InGroup<Documentation>, DefaultIgnore;

def warn_doc_tparam_duplicate : Warning<
  "template parameter '%0' is already documented">,
  InGroup<Documentation>, DefaultIgnore;

def note_doc_tparam_previous : Note<
  "previous documentation">;

def warn_doc_tparam_not_found : Warning<
  "template parameter '%0' not found in the template declaration">,
  InGroup<Documentation>, DefaultIgnore;

def note_doc_tparam_name_suggestion : Note<
  "did you mean '%0'?">;

// \returns command

def warn_doc_returns_not_attached_to_a_function_decl : Warning<
  "'%select{\\|@}0%1' command used in a comment that is not attached to "
  "a function or method declaration">,
  InGroup<Documentation>, DefaultIgnore;

def warn_doc_returns_attached_to_a_void_function : Warning<
  "'%select{\\|@}0%1' command used in a comment that is attached to a "
  "%select{function returning void|constructor|destructor|"
  "method returning void}2">,
  InGroup<Documentation>, DefaultIgnore;

// \deprecated command

def warn_doc_deprecated_not_sync : Warning<
  "declaration is marked with '\\deprecated' command but does not have "
  "a deprecation attribute">,
  InGroup<DocumentationDeprecatedSync>, DefaultIgnore;

def note_add_deprecation_attr : Note<
  "add a deprecation attribute to the declaration to silence this warning">;

// verbatim block commands

def warn_verbatim_block_end_without_start : Warning<
  "'%select{\\|@}0%1' command does not terminate a verbatim text block">,
  InGroup<Documentation>, DefaultIgnore;

def warn_unknown_comment_command_name : Warning<
  "unknown command tag name">,
  InGroup<DocumentationUnknownCommand>, DefaultIgnore;

def warn_correct_comment_command_name : Warning<
  "unknown command tag name '%0'; did you mean '%1'?">,
  InGroup<DocumentationUnknownCommand>, DefaultIgnore;

} // end of documentation issue category
} // end of AST component
