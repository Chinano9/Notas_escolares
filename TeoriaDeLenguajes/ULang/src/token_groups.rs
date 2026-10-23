use crate::token::TokenType;

pub mod keywords {
    use super::TokenType;

    pub const KEYWORDS: &[(&str, TokenType)] = &[
        ("let", TokenType::Let),
        ("const", TokenType::Const),
        ("mut", TokenType::Mut),
        ("function", TokenType::Function),
        ("return", TokenType::Return),
        ("if", TokenType::If),
        ("else", TokenType::Else),
        ("for", TokenType::For),
        ("while", TokenType::While),
        ("switch", TokenType::Switch),
        ("case", TokenType::Case),
        ("default", TokenType::Default),
        ("break", TokenType::Break),
        ("continue", TokenType::Continue),
        ("yield", TokenType::Yield),
        ("try", TokenType::Try),
        ("catch", TokenType::Catch),
        ("finally", TokenType::Finally),
        ("throw", TokenType::Throw),
        ("import", TokenType::Import),
        ("export", TokenType::Export),
        ("namespace", TokenType::Namespace),
        ("using", TokenType::Using),
        ("extends", TokenType::Extends),
        ("implements", TokenType::Implements),
        ("new", TokenType::New),
        ("this", TokenType::This),
        ("super", TokenType::Super),
        ("async", TokenType::Async),
        ("await", TokenType::Await),
        ("thread", TokenType::Thread),
        ("lock", TokenType::Lock),
        ("unlock", TokenType::Unlock),
        ("pointer", TokenType::Pointer), // Asumiendo que 'pointer' es una palabra clave
        ("reference", TokenType::Reference), // Asumiendo que 'reference' es una palabra clave
        ("dereference", TokenType::Dereference), // Asumiendo que 'dereference' es una palabra clave
        ("generic", TokenType::Generic),
        ("template", TokenType::Template),
    ];
}

pub mod literals {
    use super::TokenType;

    pub const LITERALS: &[(&str, TokenType)] = &[
        ("true", TokenType::True),
        ("false", TokenType::False),
        ("null", TokenType::Null),
    ];
}

pub mod data_types {
    use super::TokenType;

    pub const DATA_TYPES: &[(&str, TokenType)] = &[
        ("int", TokenType::Int),
        ("int8", TokenType::Int8),
        ("int16", TokenType::Int16),
        ("int32", TokenType::Int32),
        ("int64", TokenType::Int64),
        ("uint", TokenType::UInt),
        ("uint8", TokenType::UInt8),
        ("uint16", TokenType::UInt16),
        ("uint32", TokenType::UInt32),
        ("uint64", TokenType::UInt64),
        ("float", TokenType::Float),
        ("float32", TokenType::Float32),
        ("float64", TokenType::Float64),
        ("bool", TokenType::Bool),
        ("string", TokenType::StringType),
        ("char", TokenType::Char),
        ("void", TokenType::Void),
        ("array", TokenType::Array),
        ("map", TokenType::Map),
        ("struct", TokenType::Struct),
        ("enum", TokenType::Enum),
        ("class", TokenType::Class),
        ("interface", TokenType::Interface),
    ];
}

pub mod access_modifiers {
    use super::TokenType;

    pub const ACCESS_MODIFIERS: &[(&str, TokenType)] = &[
        ("public", TokenType::Public),
        ("private", TokenType::Private),
        ("protected", TokenType::Protected),
    ];
}

pub mod operators {
    use super::TokenType;

    pub const OPERATORS: &[(&str, TokenType)] = &[
        // Asignaciones
        ("=", TokenType::Assign),
        ("+=", TokenType::PlusAssign),
        ("-=", TokenType::MinusAssign),
        ("*=", TokenType::AsteriskAssign),
        ("/=", TokenType::SlashAssign),
        ("%=", TokenType::ModuloAssign),
        ("??=", TokenType::NullCoalescingAssign),
        // Incremento y decremento
        ("++", TokenType::Increment),
        ("--", TokenType::Decrement),
        // Aritméticos
        ("+", TokenType::Plus),
        ("-", TokenType::Minus),
        ("*", TokenType::Asterisk),
        ("/", TokenType::Slash),
        ("%", TokenType::Modulo),
        // Lógicos
        ("&&", TokenType::And),
        ("||", TokenType::Or),
        ("!", TokenType::Not),
        // Bit a bit
        ("&", TokenType::BitAnd),
        ("|", TokenType::BitOr),
        ("^", TokenType::BitXor),
        ("~", TokenType::BitNot),
        ("<<", TokenType::LeftShift),
        (">>", TokenType::RightShift),
        // Comparación
        ("==", TokenType::Equal),
        ("!=", TokenType::NotEqual),
        ("<", TokenType::LessThan),
        ("<=", TokenType::LessThanOrEqual),
        (">", TokenType::GreaterThan),
        (">=", TokenType::GreaterThanOrEqual),
        // Otros
        ("?", TokenType::OptionalChaining), // El original tenía '?.', lo moví aquí para una mejor clasificación.
        ("...", TokenType::Spread),
        ("->", TokenType::Arrow), // El literal 'Arrow' no estaba implementado
        (".", TokenType::Dot),
        ("::", TokenType::ScopeResolution),
        ("@", TokenType::Annotation),
        ("#", TokenType::Preprocessor),
        ("??", TokenType::NullCoalescing),
    ];
}

pub mod delimiters {
    use super::TokenType;

    pub const DELIMITERS: &[(&str, TokenType)] = &[
        ("(", TokenType::LeftParen),
        (")", TokenType::RightParen),
        ("{", TokenType::LeftBrace),
        ("}", TokenType::RightBrace),
        ("[", TokenType::LeftBracket),
        ("]", TokenType::RightBracket),
        (",", TokenType::Comma),
        (";", TokenType::SemiColon),
        (":", TokenType::Colon),
    ];
}

pub mod comments {
    use super::TokenType;

    pub const COMMENTS: &[(&str, TokenType)] = &[
        ("//", TokenType::Comment),
        ("/*", TokenType::Comment),
        ("/**", TokenType::DocComment),
        ("*/", TokenType::Comment),
    ];
}
