-- -----------------------------------------------------
-- Table `studies`.`trabalha`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `studies`.`trabalha` (
  `CPF` INT(11) NOT NULL,
  `codigo` INT(11) NOT NULL,
  `funcao` VARCHAR(60) NULL DEFAULT NULL,
  `data_ini` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`CPF`, `codigo`),
  INDEX `fk_proj_idx` (`codigo` ASC) VISIBLE,
  CONSTRAINT `fk_func`
    FOREIGN KEY (`CPF`)
    REFERENCES `studies`.`funcionario` (`CPF`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_proj`
    FOREIGN KEY (`codigo`)
    REFERENCES `studies`.`projeto` (`codigo`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = latin1;