#
# Copyright (C) 2003-2013 Sebastien Helleu <flashcode@flashtux.org>
# Copyright (C) 2006 Julien Louis <ptitlouis@sysif.net>
#
# This file is part of WeeChat, the extensible chat client.
#
# WeeChat is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# WeeChat is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with WeeChat.  If not, see <http://www.gnu.org/licenses/>.
#

docdir = $(datadir)/doc/$(PACKAGE)

EXTRA_DIST = CMakeLists.txt \
             weechat.1.fr.txt \
             cmdline_options.fr.txt \
             weechat_user.fr.txt \
             weechat_plugin_api.fr.txt \
             weechat_scripting.fr.txt \
             weechat_faq.fr.txt \
             weechat_quickstart.fr.txt \
             weechat_tester.fr.txt \
             $(wildcard autogen/user/*.txt) \
             $(wildcard autogen/plugin_api/*.txt)

if MAN
  man_targets = weechat.1
  man_install = install-man
  man_uninstall = uninstall-man
endif
if DOC
  doc_targets = weechat_user.fr.html \
		weechat_plugin_api.fr.html \
		weechat_scripting.fr.html \
		weechat_faq.fr.html \
		weechat_quickstart.fr.html \
		weechat_tester.fr.html
  doc_install = install-doc
  doc_uninstall = uninstall-doc
endif
all-local: $(man_targets) $(doc_targets)

# man page
weechat.1: weechat.1.fr.txt cmdline_options.fr.txt
	cp -f $(abs_top_srcdir)/doc/fr/weechat.1.fr.txt .
	cp -f $(abs_top_srcdir)/doc/fr/cmdline_options.fr.txt .
	$(A2X) -a lang=fr -a revision="WeeChat $(VERSION)" -d manpage -f manpage -L weechat.1.fr.txt

# user's guide
weechat_user.fr.html: weechat_user.fr.txt cmdline_options.fr.txt $(wildcard autogen/user/*.txt)
	$(ASCIIDOC) -a lang=fr -a toc -a toclevels=4 -a date=`date "+%F"` -a revision="$(VERSION)" -a stylesheet=$(abs_top_srcdir)/doc/asciidoc.css -f $(abs_top_srcdir)/doc/asciidoc.conf -n -o weechat_user.fr.html $(abs_top_srcdir)/doc/fr/weechat_user.fr.txt

# plugin API reference
weechat_plugin_api.fr.html: weechat_plugin_api.fr.txt $(wildcard autogen/plugin_api/*.txt)
	$(ASCIIDOC) -a lang=fr -a toc -a toclevels=4 -a date=`date "+%F"` -a revision="$(VERSION)" -a stylesheet=$(abs_top_srcdir)/doc/asciidoc.css -n -o weechat_plugin_api.fr.html $(abs_top_srcdir)/doc/fr/weechat_plugin_api.fr.txt

# scripting guide
weechat_scripting.fr.html: weechat_scripting.fr.txt
	$(ASCIIDOC) -a lang=fr -a toc -a toclevels=3 -a date=`date "+%F"` -a revision="$(VERSION)" -a stylesheet=$(abs_top_srcdir)/doc/asciidoc.css -n -o weechat_scripting.fr.html $(abs_top_srcdir)/doc/fr/weechat_scripting.fr.txt

# FAQ
weechat_faq.fr.html: weechat_faq.fr.txt
	$(ASCIIDOC) -a lang=fr -a toc -a date=`date "+%F"` -a revision="$(VERSION)" -a stylesheet=$(abs_top_srcdir)/doc/asciidoc.css -f $(abs_top_srcdir)/doc/asciidoc.conf -n -o weechat_faq.fr.html $(abs_top_srcdir)/doc/fr/weechat_faq.fr.txt

# quickstart
weechat_quickstart.fr.html: weechat_quickstart.fr.txt
	$(ASCIIDOC) -a lang=fr -a toc -a date=`date "+%F"` -a revision="$(VERSION)" -a stylesheet=$(abs_top_srcdir)/doc/asciidoc.css -n -o weechat_quickstart.fr.html $(abs_top_srcdir)/doc/fr/weechat_quickstart.fr.txt

# tester's guide
weechat_tester.fr.html: weechat_tester.fr.txt
	$(ASCIIDOC) -a lang=fr -a toc -a date=`date "+%F"` -a revision="$(VERSION)" -a stylesheet=$(abs_top_srcdir)/doc/asciidoc.css -n -o weechat_tester.fr.html $(abs_top_srcdir)/doc/fr/weechat_tester.fr.txt

# install man/docs

install-data-hook: $(man_install) $(doc_install)

install-man:
	$(mkinstalldirs) $(DESTDIR)$(mandir)/fr/man1/
	$(INSTALL_DATA) *.1 $(DESTDIR)$(mandir)/fr/man1/

install-doc:
	$(mkinstalldirs) $(DESTDIR)$(docdir)/
	$(INSTALL_DATA) *.html $(DESTDIR)$(docdir)/

# uninstall man/docs

uninstall-hook: $(man_uninstall) $(doc_uninstall)

uninstall-man:
	$(RM) $(DESTDIR)$(mandir)/fr/man1/weechat.1
	-rmdir $(DESTDIR)$(mandir)/fr/man1

uninstall-doc:
	$(RM) $(DESTDIR)$(docdir)/*.fr.html
	-rmdir $(DESTDIR)$(docdir)

# clean

clean-local:
	-rm -f weechat.1
	-rm -f *.html
