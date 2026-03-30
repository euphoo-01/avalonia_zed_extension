module.exports = grammar({
    name: 'avalonia',

    extras: $ => [
        /\s/,
        $.comment
    ],

    rules: {
        document: $ => repeat($._node),

        _node: $ => choice(
            $.element,
            $.empty_element
        ),

        element: $ => seq(
            $.open_tag,
            repeat($._node),
            $.close_tag
        ),

        open_tag: $ => seq(
            '<',
            $.tag_name,
            repeat($.attribute),
            '>'
        ),

        close_tag: $ => seq(
            '</',
            $.tag_name,
            '>'
        ),

        empty_element: $ => seq(
            '<',
            $.tag_name,
            repeat($.attribute),
            '/>'
        ),

        attribute: $ => seq(
            $.attribute_name,
            '=',
            choice(
                $.attribute_value,
                $.markup_extension
            )
        ),

        tag_name: $ => /[\w\.:]+/,
        attribute_name: $ => /[\w\.:]+/,
        attribute_value: $ => seq(
            '"',
            /[^"]*/,
            '"'
        ),

        markup_extension: $ => seq(
            '{',
            /[^}]+/,
            '}'
        ),

        comment: $ => seq('<!--', /.*/, '-->')
    }
});
