/*
 * Copyright (c) 2003-2009 by FlashCode <flashcode@flashtux.org>
 * See README for License detail, AUTHORS for developers list.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __WEECHAT_IRC_CTCP_H
#define __WEECHAT_IRC_CTCP_H 1

struct t_irc_server;
struct t_irc_channel;

struct t_irc_ctcp_reply
{
    char *name;                     /* CTCP name                             */
    char *reply;                    /* CTCP reply format                     */
};

extern const char *irc_ctcp_get_default_reply (const char *ctcp);
extern void irc_ctcp_display_reply_from_nick (struct t_irc_server *server,
                                              const char *command,
                                              const char *nick,
                                              char *arguments);
extern void irc_ctcp_recv (struct t_irc_server *server, const char *command,
                           struct t_irc_channel *channel, const char *address,
                           const char *nick, const char *remote_nick,
                           char *arguments, char *message);

#endif /* irc-ctcp.h */