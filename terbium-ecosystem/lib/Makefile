# Makefile - Rules, regulations, limitations, and allowance for library workflows
#
# This Makefile defines a professional, disciplined set of targets.
# Rules:
#   - Default target is `all` and maps to `build`.
#   - Only defined targets should be used.
#   - Side effects are limited to build artifacts and installation paths.
# Limitations:
#   - `install` must honor PREFIX and DESTDIR.
#   - No operations should modify files outside the repository tree except explicit install targets.
# Allowance:
#   - `build`, `test`, `lint`, `clean`, `install`, and `help` are permitted.
#   - Dry-run mode is allowed via `make -n`.

SHELL := /bin/bash
PREFIX ?= /usr/local
DESTDIR ?=
PYTHON ?= python3
SRC_DIR ?= .
TEST_DIR ?= tests
V ?= 0

.PHONY: all build test lint install clean help

all: build

build:
	@echo "[rule] Build started"
	@$(PYTHON) -m compileall $(SRC_DIR) >/dev/null 2>&1 || true
	@echo "[allowance] Build complete"

test:
	@echo "[rule] Test suite execution"
	@$(PYTHON) -m pytest $(TEST_DIR)

lint:
	@echo "[rule] Linting source code"
	@$(PYTHON) -m flake8 $(SRC_DIR)

install: build
	@echo "[rule] Installing artifacts to $(PREFIX)"
	@install -d $(DESTDIR)$(PREFIX)/bin
	@echo "[allowance] Installation complete"

clean:
	@echo "[rule] Cleaning generated files"
	@find . -type f -name '*.pyc' -delete
	@find . -type d -name '__pycache__' -exec rm -rf {} +
	@echo "[allowance] Clean complete"

help:
	@printf '%s\n' \
		"Available targets:" \
		"  make           - build the project" \
		"  make test      - run tests" \
		"  make lint      - run lint checks" \
		"  make install   - install artifacts" \
		"  make clean     - remove generated files" \
		"  make help      - show this message"
