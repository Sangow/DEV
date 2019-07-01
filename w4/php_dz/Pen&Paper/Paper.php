<?php
    class Paper {
        private $maxSymbols, $symbols, $content;

        public function __construct($maxSymbols = 4096) {
            $this->maxSymbols = $maxSymbols;
            $this->symbols = 0;
            $this->content = "";
        }

        public function __get($name) {
            if ( property_exists($this, $name) && is_numeric($this->$name) ) {
                var_dump(is_numeric($this->$name));
                return $this->$name;
            }
            throw new Exception("Attribute $name not found OR you trying to get $content field!");
        }

        public function addContent($message) {
            if ( $this->symbols == $this->maxSymbols ) {
                throw new Exception("OutOfSpace!");
            }
            $maxInputSymbols = $this->maxSymbols - $this->symbols;

            if ( $maxInputSymbols < strlen($message) ) {
                $this->symbols = $this->maxSymbols;
                $this->content .= substr($message, 0, $maxInputSymbols);
                return;
            }

            $this->symbols += strlen($message);
            $this->content .= $message;
        }

        public function show() {
            printf("Paper: %d/%d symbols;" . PHP_EOL .
                    "Content: [%s]." . PHP_EOL, $this->symbols, $this->maxSymbols,
                                    $this->content);
        }
    }
?>