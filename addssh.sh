#!/bin/bash

# This code simply adds a ssh key into eval in order to make stuff simpler and faster

eval $(ssh-agent)

$(ssh-add $1)

