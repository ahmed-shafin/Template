set nocompatible
set number
set relativenumber
set tabstop=4
set shiftwidth=4
set expandtab
set autoindent
syntax on
set clipboard=unnamedplus

inoremap jj <Esc>
nnoremap <F5> :w<CR>:!g++ -std=c++17 -O2 % -o %:r<CR>
nnoremap <F6> :!./%:r<CR>
inoremap {<CR> {<CR>}<CR><Esc>kO<Tab>
