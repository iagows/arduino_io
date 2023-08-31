info:	      # This list
	@clear
	@echo ""
	@echo '███████╗██████╗ ██╗ ██████╗ '
	@echo '██╔════╝██╔══██╗██║██╔═══██╗'
	@echo '███████╗██████╔╝██║██║   ██║'
	@echo '╚════██║██╔══██╗██║██║   ██║'
	@echo '███████║██║  ██║██║╚██████╔╝'
	@echo '╚══════╝╚═╝  ╚═╝╚═╝ ╚═════╝ '
	@echo ""
	@cat $(MAKEFILE_LIST) | grep -e "^[a-zA-Z_\-]*: *.*"

lint:         # Arduino Lint
	@arduino-lint --library-manager update

tag:	# tag example
	@tag=$$(echo '$(filter-out $@,$(MAKECMDGOALS))' | tr -d '[:space:]'); \
	git tag $$tag
	@git push origin --tags
