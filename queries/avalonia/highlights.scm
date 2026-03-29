; XML Tags
(tag_name) @tag

; Attributes
(attribute_name) @property
(quoted_attribute_value (string)) @string

; Comments
(comment) @comment

; Special XML elements
(prolog) @keyword
(XMLDecl) @keyword
(DocTypeDecl) @keyword
(pi_target) @keyword
(pi_content) @string

; Brackets and Delimiters
"<![CDATA[" @string.special
"]]>"" @string.special
"<" @punctuation.bracket
"/>" @punctuation.bracket
">" @punctuation.bracket
"</" @punctuation.bracket
"=" @operator

; Avalonia-Specific Highlighting

; Markup Extensions e.g. {Binding Classes}
(attribute
  (quoted_attribute_value
    (string
      "{" @punctuation.bracket
      (contents) @variable.builtin
      "}" @punctuation.bracket
    )
  )
)

; Style Selectors e.g. Button.primary:pointerover
(attribute
  (attribute_name) @property
  (quoted_attribute_value (string) @string.special)
  (#eq? @property "Selector")
)

; Avalonia Control Themes and special tags
(tag_name) @type.definition
(#match? @type.definition "^(Style|Setter|Template)$")