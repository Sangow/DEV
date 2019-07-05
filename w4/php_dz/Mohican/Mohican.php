<?php
    class Mohican {
        private static $lastMohican;
        private static $sID = 1;
        private $id;
        private $name;

        public function __construct($name = "Gogi") {
            $this->id = self::$sID;
            self::$sID += 1;
            $this->name = $name;
            self::$lastMohican = $this;
        }

        public static function getLastMohican() {
            return self::$lastMohican;
        }

        public function __toString() {
            return sprintf("Name:\t%s;" . PHP_EOL .
                            "ID:\t%d.", $this->name, $this->id);
        }
    }
?>