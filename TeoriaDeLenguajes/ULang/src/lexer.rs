pub struct Lexer<'a> {
    input: &'a str,
    position: usize,      // Posición actual en el `input`
    read_position: usize, // Siguiente posición a leer
    ch: char,             // Carácter actual bajo examen
}

impl<'a> Lexer<'a> {
    pub fn new(input: &'a str) -> Self {
        let mut l = Lexer {
            input,
            position: 0,
            read_position: 0,
            ch: '\0',
        };
        l.read_char(); // Inicializa el primer carácter
        l
    }

    fn peek_char(&self) -> char {
        if self.read_position >= self.input.len() {
            '\0'
        } else {
            self.input.chars().nth(self.read_position).unwrap()
        }
    }

    fn read_char(&mut self) {
        if self.read_position >= self.input.len() {
            self.ch = '\0'; // EOF
        } else {
            self.ch = self.input.chars().nth(self.read_position).unwrap();
        }
        self.position = self.read_position;
        self.read_position += 1;
    }

    fn keyword_map() -> std::collections::HashMap<&'static str, TokenType> {
        use TokenType::*;
        let mut map = std::collections::HashMap::new();
        map.insert("let", Let);
        map.insert("const", Const);
        map.insert("mut", Mut);
        map.insert("fn", Fn);
        map.insert("return", Return);
        map.insert("if", If);
        map.insert("else", Else);
        map.insert("for", For);
        map.insert("true", Identifier("true".to_string()));
        map.insert("false", Identifier("false".to_string()));
        map.insert("null", Identifier("null".to_string()));
        map.insert("int", Int);
        map.insert("int8", Int8);
        map.insert("int16", Int16);
        map.insert("int32", Int32);
        map.insert("int64", Int64);
        map.insert("uint", UInt);
        map.insert("uint8", UInt8);
        map.insert("uint16", UInt16);
        map.insert("uint32", UInt32);
        map.insert("uint64", UInt64);
        map.insert("float", Float);
        map.insert("float32", Float32);
        map.insert("float64", Float64);
        map.insert("bool", Bool);
        map.insert("string", StringType);
        map.insert("char", Char);
        map.insert("void", Void);
        map.insert("[]", Array);
        map.insert("map", Map);
    }

    fn read_identifier(&mut self) -> String {
        let position = self.position;
        while self.ch.is_alphanumeric() || self.ch == '_' {
            self.read_char();
        }
        self.input[position..self.position].to_string()
    }

    fn lookup_identifier(&self, ident: &str) -> TokenType {
        let map = Lexer::keyword_map();
        match map.get(ident) {
            Some(token_type) => token_type.clone(),
            None => TokenType::Identifier(ident.to_string()),
        }
    }

    pub fn next_token(&mut self) -> Token {
        // Lógica para saltar espacios en blanco
        self.skip_whitespace();

        let token = match self.ch {
            '\0' => Token {
                token_type: TokenType::EOF,
                literal: "".to_string(),
            },
            '+' => Token {
                token_type: TokenType::Plus,
                literal: self.ch.to_string(),
            },
            '-' => Token {
                token_type: TokenType::Minus,
                literal: self.ch.to_string(),
            },
            '*' => Token {
                token_type: TokenType::Asterisk,
                literal: self.ch.to_string(),
            },
            '/' => Token {
                token_type: TokenType::Slash,
                literal: self.ch.to_string(),
            },
            '%' => Token {
                token_type: TokenType::Modulo,
                literal: self.ch.to_string(),
            },
            '!' => {
                if self.peek_char() == '=' {
                    self.read_char();
                    Token {
                        token_type: TokenType::BangEqual,
                        literal: "!=".to_string(),
                    }
                } else {
                    Token {
                        token_type: TokenType::Illegal,
                        literal: self.ch.to_string(),
                    }
                }
            }
            '<' => {
                if self.peek_char() == '=' {
                    self.read_char();
                    Token {
                        token_type: TokenType::LessEqual,
                        literal: "<=".to_string(),
                    }
                } else {
                    Token {
                        token_type: TokenType::LessThan,
                        literal: self.ch.to_string(),
                    }
                }
            }
            '>' => {
                if self.peek_char() == '=' {
                    self.read_char();
                    Token {
                        token_type: TokenType::GreaterEqual,
                        literal: ">=".to_string(),
                    }
                } else {
                    Token {
                        token_type: TokenType::GreaterThan,
                        literal: self.ch.to_string(),
                    }
                }
            }
            '=' => {
                if self.peek_char() == '=' {
                    self.read_char();
                    Token {
                        token_type: TokenType::DoubleEqual,
                        literal: "==".to_string(),
                    }
                } else {
                    Token {
                        token_type: TokenType::Equal,
                        literal: self.ch.to_string(),
                    }
                }
            }
            ';' => Token {
                token_type: TokenType::SemiColon,
                literal: self.ch.to_string(),
            },
            '(' => Token {
                token_type: TokenType::LeftParen,
                literal: self.ch.to_string(),
            },
            ')' => Token {
                token_type: TokenType::RightParen,
                literal: self.ch.to_string(),
            },
            '{' => Token {
                token_type: TokenType::LeftBrace,
                literal: self.ch.to_string(),
            },
            '}' => Token {
                token_type: TokenType::RightBrace,
                literal: self.ch.to_string(),
            },
            '"' => {
                let literal = self.read_string();
                Token {
                    token_type: TokenType::String(literal.clone()),
                    literal,
                }
            }
            'a'..='z' | 'A'..='Z' | '_' => {
                let literal = self.read_identifier();
                let token_type = self.lookup_identifier(&literal);
                return Token {
                    token_type,
                    literal,
                };
            }
            '0'..='9' => {
                let literal = self.read_number();
                return Token {
                    token_type: TokenType::Number(literal.parse().unwrap()),
                    literal,
                };
            }

            _ => Token {
                token_type: TokenType::Illegal,
                literal: self.ch.to_string(),
            },
        };

        self.read_char();
        token
    }

    fn read_string(&mut self) -> String {
        // Avanzamos después de las comillas iniciales
        self.read_char();

        let position = self.position;
        while self.ch != '"' && self.ch != '\0' {
            // Manejo de caracteres de escape
            if self.ch == '\\' && self.peek_char() == '"' {
                self.read_char(); // Consume el backslash
            }
            self.read_char();
        }

        if self.ch == '\0' {
            // Error: string no terminado
            return String::new();
        }

        let str_content = self.input[position..self.position].to_string();
        self.read_char(); // Consume las comillas finales
        str_content
    }

    fn read_number(&mut self) -> String {
        let position = self.position;
        let mut has_decimal = false;

        while self.ch.is_digit(10) || (self.ch == '.' && !has_decimal) {
            if self.ch == '.' {
                has_decimal = true;
            }
            self.read_char();
        }

        self.input[position..self.position].to_string()
    }

    fn skip_whitespace(&mut self) {
        while self.ch.is_whitespace() {
            self.read_char();
        }
    }
}
