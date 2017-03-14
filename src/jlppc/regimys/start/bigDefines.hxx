#ifndef BIGDEFINES_HXX_INCLUDED
#define BIGDEFINES_HXX_INCLUDED

#define NAME_ENTRY case SDL_KEYUP:\
						switch (events.key.keysym.sym) {\
							case SDLK_RSHIFT:\
								shift = false;\
								break;\
							case SDLK_LSHIFT:\
								shift = false;\
								break;\
						}\
						break;\
\
					case SDL_KEYDOWN:\
						switch (events.key.keysym.sym) {\
								ECHAP\
\
							case SDLK_LSHIFT:\
								shift = true;\
								break;\
\
							case SDLK_RSHIFT:\
								shift = true;\
								break;\
\
							case SDLK_CAPSLOCK:\
								if (!caps) {\
									shift = true;\
									caps = true;\
								} else {\
									shift = false;\
									caps = false;\
								}\
\
\
								break;\
\
							case SDLK_BACKSPACE:\
								pName[k] = ' ';\
								if (k != 0) {\
									k--;\
								}\
\
\
								break;\
\
							case SDLK_a:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'A';\
								} else {\
									pName[k] = 'a';\
								}\
\
								break;\
\
							case SDLK_b:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'B';\
								} else {\
									pName[k] = 'b';\
								}\
\
								break;\
\
							case SDLK_c:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'C';\
								} else {\
									pName[k] = 'c';\
								}\
\
								break;\
\
							case SDLK_d:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'D';\
								} else {\
									pName[k] = 'd';\
								}\
\
								break;\
\
							case SDLK_e:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'E';\
								} else {\
									pName[k] = 'e';\
								}\
\
								break;\
\
							case SDLK_f:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'F';\
								} else {\
									pName[k] = 'f';\
								}\
\
								break;\
\
							case SDLK_g:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'G';\
								} else {\
									pName[k] = 'g';\
								}\
\
								break;\
\
							case SDLK_h:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'H';\
								} else {\
									pName[k] = 'h';\
								}\
\
								break;\
\
							case SDLK_i:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'i';\
								} else {\
									pName[k] = 'i';\
								}\
\
								break;\
\
							case SDLK_j:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'J';\
								} else {\
									pName[k] = 'j';\
								}\
\
								break;\
\
							case SDLK_k:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'K';\
								} else {\
									pName[k] = 'k';\
								}\
\
								break;\
\
							case SDLK_l:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'L';\
								} else {\
									pName[k] = 'l';\
								}\
\
								break;\
\
							case SDLK_m:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'M';\
								} else {\
									pName[k] = 'm';\
								}\
\
								break;\
\
							case SDLK_n:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'N';\
								} else {\
									pName[k] = 'n';\
								}\
\
								break;\
\
							case SDLK_o:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'O';\
								} else {\
									pName[k] = 'o';\
								}\
\
								break;\
\
							case SDLK_p:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'P';\
								} else {\
									pName[k] = 'p';\
								}\
\
								break;\
\
							case SDLK_q:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'Q';\
								} else {\
									pName[k] = 'q';\
								}\
\
								break;\
\
							case SDLK_r:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'R';\
								} else {\
									pName[k] = 'r';\
								}\
\
								break;\
\
							case SDLK_s:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'S';\
								} else {\
									pName[k] = 's';\
								}\
\
								break;\
\
							case SDLK_t:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'T';\
								} else {\
									pName[k] = 't';\
								}\
\
								break;\
\
							case SDLK_u:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'U';\
								} else {\
									pName[k] = 'u';\
								}\
\
								break;\
\
							case SDLK_v:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'V';\
								} else {\
									pName[k] = 'v';\
								}\
\
								break;\
\
\
\
							case SDLK_w:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'W';\
								} else {\
									pName[k] = 'w';\
								}\
\
								break;\
\
							case SDLK_x:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'X';\
								} else {\
									pName[k] = 'x';\
								}\
								break;\
\
							case SDLK_y:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'Y';\
								} else {\
									pName[k] = 'y';\
								}\
								break;\
\
							case SDLK_z:\
								if (k != 14) {\
									k++;\
								}\
								if (shift) {\
									pName[k] = 'Z';\
								} else {\
									pName[k] = 'z';\
								}\
								break;\
\
							case SDLK_0:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '0';\
								break;\
\
							case SDLK_1:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '1';\
								break;\
\
							case SDLK_2:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '2';\
								break;\
\
							case SDLK_3:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '3';\
								break;\
\
							case SDLK_4:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '4';\
								break;\
\
							case SDLK_5:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '5';\
								break;\
\
							case SDLK_6:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '6';\
								break;\
\
							case SDLK_7:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '7';\
								break;\
\
							case SDLK_8:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '8';\
								break;\
\
							case SDLK_9:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '9';\
								break;\
\
							case SDLK_KP_0:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '0';\
								break;\
\
							case SDLK_KP_1:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '1';\
								break;\
\
							case SDLK_KP_2:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '2';\
								break;\
\
							case SDLK_KP_3:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '3';\
								break;\
\
							case SDLK_KP_4:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '4';\
								break;\
\
							case SDLK_KP_5:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '5';\
								break;\
\
							case SDLK_KP_6:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '6';\
								break;\
\
							case SDLK_KP_7:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '7';\
								break;\
\
							case SDLK_KP_8:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '8';\
								break;\
\
							case SDLK_KP_9:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = '9';\
								break;\
							case SDLK_DELETE:\
								if (k != 14) {\
									k++;\
								}\
								pName[k] = ' ';\
								break;\
							case SDLK_RETURN:\
								bool voided = true;\
								int voidNumber = 0;\
								int indexEnd = 0;\
								for (unsigned int l = 0; l < 15; l++) {\
									if (pName[l] != ' ') {\
										voided = false;\
										voidNumber = 0;\
									} else {\
										voidNumber++;\
									}\
									if (voidNumber >= 2) {\
										indexEnd = l - 1;\
										break;\
									}\
								}\
								rerrLog << "OK2" << endl;\
								if (voided) {\
									pName[0] = ' ';\
									pName[0 + 1] = 'R';\
									pName[1 + 1] = 'o';\
									pName[2 + 1] = 'b';\
									pName[3 + 1] = 'e';\
									pName[4 + 1] = 'r';\
									pName[5 + 1] = 't';\
									pName[6 + 1] = '\0';\
								} else {\
                                    if(indexEnd != 0){\
                                        pName[indexEnd] = '\0';\
                                    }\
								}\
								continuer = false;\
								rerrLog << "OK" << endl;\
								break;\
\
\
						break;\
						}\
						break;

#endif // BIGDEFINES_HXX_INCLUDED
