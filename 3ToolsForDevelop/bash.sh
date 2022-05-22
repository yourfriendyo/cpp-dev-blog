" Do something if running at least Vim 7.4.42 with +profile enabled.
if (v:version > 704 || v:version == 704 && has('patch42')) && has('profile')
  " do stuff
endif
