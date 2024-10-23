-- -----------------------------------------------------
-- Table `studies`.`funcionario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `studies`.`funcionario` (
  `CPF` INT(11) NOT NULL,
  `nome` VARCHAR(100) NOT NULL,
  `peso` FLOAT NULL DEFAULT NULL,
  `altura` FLOAT NULL DEFAULT NULL,
  PRIMARY KEY (`CPF`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1;
