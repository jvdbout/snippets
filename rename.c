{\rtf1\ansi\ansicpg1252\deff0\deflang1033{\fonttbl{\f0\fnil\fcharset0 Courier New;}{\f1\fnil Courier New;}{\f2\fswiss\fcharset0 Arial;}}
\viewkind4\uc1\pard\f0\fs18 /* Rename Command, Creates An item and sets a wear flag\par
 * Used For Giving out Treasure items on my mud\par
 * without any hasstle, Created By Jinru\par
 * You may use this snippet as long as you keep this tag in\par
 */\par
\par
 /* Pase this code anywhere */\f1\par
void do_rename(CHAR_DATA *ch, char *argument )\par
\{\par
    OBJ_DATA *o;\par
    OBJ_INDEX_DATA *pObjIndex;\par
    char arg1[MAX_INPUT_LENGTH];\par
    int value = 0;\par
\par
  \f0   \f1 argument = one_argument( argument, arg1 );\par
\par
    if( IS_NPC(ch) )\par
          return;\par
\par
    if( arg1[0] == '\\0' )\par
    \{\par
\tab ch_printf(ch,"\\n\\rSyntax: rename <item>\f0  <flag>\f1\\n\\r");\par
\tab ch_printf(ch,"\\n\\r");\par
\tab return;\par
    \}\par
  \par
    if( ch->carry_number >= 19 )\f0  /* Used For certain things,you can commet it out if you dont need it*/\f1\par
    \{\par
\tab ch_printf(ch,"You haven't got any room.\\n\\r");\par
\tab return;\par
    \}\par
\par
\f0    \f1  if ( ch->level > 55 )\par
    \{\par
\tab int a = 1416; \par
/* \f0 NOTE: a must be a vnum already created in your mud, name it like rename item and set the item specifics you want, like armor values or what-not and then just remove the prototype flag and save it\f1  */\par
\tab\par
\tab if( a == 0 )\par
\tab\{\par
\tab   bug("Serious problem in function Rename",0);\par
\tab   return;\par
\tab\}\par
       \par
\tab act( AT_SKILL, "You use your immortal powers renaming a item at your command.", ch, NULL, NULL, TO_CHAR );\par
\tab act( AT_SKILL, "$n uses $s immortal powers renaming a item at $s command.", ch, NULL, NULL, TO_NOTVICT );\par
       ;\par
\tab pObjIndex = get_obj_index( a );\par
       ch_printf(ch, "You have named a item to %s\\n\\r", arg1 );\par
\tab o = create_object_new( pObjIndex, 1 , ORIGIN_OINVOKE, ch->name );\par
\tab o = obj_to_char( o, ch );\par
\tab save_char_obj( ch );\par
       o->name = STRALLOC( arg1 );\par
       o->short_descr = STRALLOC( arg1 );\par
       o->description = STRALLOC( arg1 );\par
       value = get_wflag( argument );\par
      \f0  \f1 if ( value < 0 || value > 31 )\par
\tab     ch_printf( ch, "Unknown flag: %s\\n\\r", argument );\par
\tab    else\par
\tab    \f0  \f1 TOGGLE_BIT( o->wear_flags, 1 << value );\par
       \par
    \}\par
   \par
\}\par
\f2\fs20\par
}
 