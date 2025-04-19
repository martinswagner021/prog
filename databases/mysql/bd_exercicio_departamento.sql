-- -----------------------------------------------------
-- Table `studies`.`departamento`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `studies`.`departamento` (
  `codigo` INT(11) NOT NULL,
  `nome` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`codigo`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1;
