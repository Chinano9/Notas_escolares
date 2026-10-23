#[derive(Debug, PartialEq, Clone)]
pub enum TokenType {
    // Palabras clave
    Let,
    Const,
    Mut,
    Function,
    Return,
    If,
    Else,
    For,
    True,
    False,
    Null,
    Type,
    // Tipos de datos
    Int,
    Int8,
    Int16,
    Int32,
    Int64,
    UInt,
    UInt8,
    UInt16,
    UInt32,
    UInt64,
    Float,
    Float32,
    Float64,
    Bool,
    StringType,
    Char,
    // Tipos especiales
    Void,
    // Tipos de datos compuestos
    Array,
    Map,
    // Tipos de datos personalizados
    Struct,
    Enum,
    // Declaraciones de acceso
    Public,
    Private,
    Protected,
    // Declaraciones de control de flujo
    While,
    Switch,
    Case,
    Default,
    Break,
    Continue,
    Yield,
    // Declaraciones de manejo de errores
    Try,
    Catch,
    Finally,
    Throw,
    // Declaraciones de importación y exportación
    Import,
    Export,
    // Declaraciones de espacio de nombres
    Namespace,
    Using,
    ScopeResolution,
    // Declaraciones de clase e interfaz
    Class,
    Interface,
    Extends,
    Implements,
    // Declaraciones de anotaciones y atributos
    Annotation,
    Preprocessor,
    // Declaraciones de concurrencia
    Async,
    Await,
    Thread,
    Lock,
    Unlock,
    // Declaraciones de memoria y punteros
    Pointer,
    Reference,
    Dereference,
    // Declaraciones de genéricos y plantillas
    Generic,
    Template,
    // Declaraciones de documentación
    DocComment,
    // Comentarios
    Comment,
    // Otros
    New,
    This,
    Super,
    NullCoalescing,
    NullCoalescingAssign,
    OptionalChaining,
    Spread,
    // Operadores lógicos
    And,
    Or,
    Not,
    // Operadores bit a bit
    BitAnd,
    BitOr,
    BitXor,
    BitNot,
    LeftShift,
    RightShift,
    // Asignaciones compuestas
    PlusAssign,
    MinusAssign,
    AsteriskAssign,
    SlashAssign,
    ModuloAssign,
    // Incremento y decremento
    Increment,
    Decrement,
    // Operadores y delimitadores
    Plus,
    Minus,
    Asterisk,
    Slash,
    Modulo,
    Assign,
    Dot,
    Comma,
    Colon,
    Arrow,
    Equal,
    NotEqual,
    LessThan,
    GreaterThan,
    LessThanOrEqual,
    GreaterThanOrEqual,
    SemiColon,
    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,
    // Literales y identificadores
    Identifier(String),
    Number(f64),
    String(String),
    Illegal, // Para caracteres no reconocidos
    EOF,     // End of File
}

#[derive(Debug, PartialEq, Clone)]
pub struct Token {
    pub token_type: TokenType,
    pub literal: String,
}
