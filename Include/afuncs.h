//////////////////////////////////////////////////////////////////////
// Acknex engine functions
// (c) Conitec / JCL 2010
// DO NOT move or edit this file!
//////////////////////////////////////////////////////////////////////
#ifndef afuncs_h
#define afuncs_h

// var = 22.10 fixed point 32-bit variable, used by C-Script.
// For other languages use the _VAR conversion function

// var math
EXT_var F(ang)(var);
EXT_var F(sign)(var);
EXT_var F(fraction)(var);
EXT_var F(integer)(var);
EXT_var F(floorv)(var);
EXT_var F(random)(var);
EXT_var F(randomize)();
EXT_var F(random_seed)(var);
EXT_var F(absv)(var);
EXT_var F(sinv)(var);
EXT_var F(cosv)(var);
EXT_var F(tanv)(var);
EXT_var F(asinv)(var);
EXT_var F(acosv)(var);
EXT_var F(atanv)(var);
EXT_var F(atan2v)(var,var);
EXT_var F(expv)(var);
EXT_var F(logv)(var);
EXT_var F(log10v)(var);
EXT_var F(sqrtv)(var);
EXT_var F(powv)(var,var);
EXT_var F(maxv)(var,var);
EXT_var F(minv)(var,var);
EXT_var F(fsin)(var,var);
EXT_var F(fcos)(var,var);
EXT_var F(ftan)(var,var);
EXT_var F(fasin)(var,var);
EXT_var F(facos)(var,var);
EXT_var F(fatan)(var,var);
EXT_var F(accelerate)(var*,var,var);
EXT_var F(clamp)(var,var,var);
EXT_var F(cycle)(var,var,var);
EXT_var F(smooth)(var*,var);
EXT_var F(floatv)(var);
EXT_var F(floatd)(var,var);
EXT_var F(floatr)(var);

// var vector math
EXT ANGLE* F(ang_add)(ANGLE*,ANGLE*);
EXT ANGLE* F(ang_rotate)(ANGLE*,ANGLE*);
EXT ANGLE* F(ang_diff)(ANGLE *a,ANGLE *a1,ANGLE *a2);
EXT ANGLE* F(ang_for_axis)(ANGLE *a, VECTOR* v,var rot);
EXT ANGLE* F(ang_for_matrix)(ANGLE *a,float* m);
EXT float* F(ang_to_matrix)(ANGLE *a,float* m);

EXT_var F(vec_length)(VECTOR*);
EXT_var F(vec_dist)(VECTOR*,VECTOR*);
EXT_var F(vec_cross)(VECTOR* a,VECTOR* b,VECTOR* c);
EXT_var F(vec_dot)(VECTOR*,VECTOR*);
EXT VECTOR* F(vec_mul)(VECTOR*,VECTOR*);
EXT VECTOR* F(vec_normalize)(VECTOR*,var);
EXT VECTOR* F(vec_accelerate)(VECTOR*,VECTOR*,VECTOR*,var);
EXT VECTOR* F(vec_bounce)(VECTOR *vRay,VECTOR *vNormal);
EXT VECTOR* F(vec_add)(VECTOR*,VECTOR*);
EXT VECTOR* F(vec_diff)(VECTOR*,VECTOR*,VECTOR*);
EXT VECTOR* F(vec_inverse)(VECTOR*);
EXT VECTOR* F(vec_lerp)(VECTOR*,VECTOR*,VECTOR*,var);
EXT VECTOR* F(vec_rotate)(VECTOR*,ANGLE*);
EXT VECTOR* F(vec_rotateback)(VECTOR*,ANGLE*);
EXT VECTOR* F(vec_rotateaxis)(VECTOR *v,VECTOR *axis,var angle);
EXT VECTOR* F(vec_scale)(VECTOR*,var);
EXT VECTOR* F(vec_set)(VECTOR*,VECTOR*);
EXT VECTOR* F(vec_fill)(VECTOR*,var);
EXT VECTOR* F(vec_sub)(VECTOR*,VECTOR*);
EXT VECTOR* F(vec_for_angle)(VECTOR*,ANGLE*);
EXT_var F(vec_to_angle)(ANGLE*,VECTOR*);
EXT VECTOR* F(vec_for_bone)(VECTOR*,ENTITY*,char* bonename);
EXT ANGLE* F(ang_for_bone)(ANGLE*,ENTITY*,char* bonename);
EXT VECTOR* F(vec_for_normal)(VECTOR*,ENTITY*,var);
EXT VECTOR* F(vec_for_vertex)(VECTOR*,ENTITY*,var);
EXT VECTOR* F(vec_for_ent)(VECTOR*,ENTITY*);
EXT VECTOR* F(vec_to_ent)(VECTOR*,ENTITY*);
EXT VECTOR* F(vec_for_min)(VECTOR*,ENTITY*);
EXT VECTOR* F(vec_for_max)(VECTOR*,ENTITY*);
EXT VECTOR* F(vec_for_mesh)(VECTOR*,ENTITY*,var);
EXT VECTOR* F(vec_to_mesh)(VECTOR*,ENTITY*,var);
EXT VECTOR* F(vec_for_uv)(VECTOR*,ENTITY*,var);
EXT VECTOR* F(vec_to_uv)(VECTOR*,ENTITY*,var);
EXT VECTOR* F(vec_for_screen)(VECTOR*,VIEW*);
EXT VECTOR* F(vec_to_screen)(VECTOR*,VIEW*);
EXT VECTOR* F(rel_for_screen)(VECTOR*,VIEW*);
EXT VECTOR* F(rel_to_screen)(VECTOR*,VIEW*);
EXT VECTOR* F(vector)(var,var,var);

// float 4x4 matrix math
EXT float* F(mat_identity)(float*);
EXT float* F(mat_inverse)(float*,float*);
EXT float* F(mat_multiply)(float*,float*);
EXT float* F(mat_scale)(float*,var,var,var);
EXT float* F(mat_set)(float*,float*);
EXT float* F(mat_transpose)(float*,float*);

// functions with char* arguments also accept a CScript STRING*.
// To distinguish, the char* must consist of at least 3 characters.
// Otherwise use the _str conversion function.
EXT STRING* F(str_create)(char *content);
EXT STRING* F(str_createw)(short *content);
EXT_var F(str_remove)(STRING*);
EXT STRING* F(str_cpy)(STRING* to,char* from);
EXT STRING* F(str_cat)(STRING* to,char* from);
EXT STRING* F(str_cat_num)(STRING *s1,char *s2,var num);
EXT STRING* F(str_printf)(STRING *s1,char *s2,...);
EXT STRING* F(str_clip)(STRING*,var);
EXT STRING* F(str_trunc)(STRING*,var);
EXT STRING* F(str_lwr)(STRING*);
EXT STRING* F(str_upr)(STRING*);
EXT_var F(str_cmp)(STRING*,char*);
EXT_var F(str_cmpi)(STRING*,char*);
EXT_var F(str_cmpni)(STRING*,char*);
EXT_var F(str_len)(char*);
EXT_var F(str_chr)(STRING*,var start,var chr);
EXT_var F(str_setchr)(STRING*,var pos,var chr);
EXT_var F(str_getchr)(STRING*,var pos);
EXT_var F(str_stri)(STRING*,char*);
EXT STRING* F(str_for_asc)(STRING*,var);
EXT_var	F(str_to_asc)(char*);
EXT STRING* F(str_for_float)(STRING*,double);
EXT STRING* F(str_for_int)(STRING*,long);
EXT STRING* F(str_for_num)(STRING*,var);
EXT double F(str_to_float)(char*);
EXT long F(str_to_int)(char*);
EXT_var F(str_to_num)(char*);
EXT_var F(str_cursor)(STRING*);
EXT_var F(str_width)(char* s,FONT* font);
EXT STRING* F(str_for_entname)(STRING*,ENTITY*);
EXT STRING* F(str_for_entfile)(STRING*,ENTITY*);
EXT STRING* F(str_for_id)(STRING*,var client_id);

// bitmap
EXT BMAP* F(bmap_create)(char* filename);
EXT BMAP* F(bmap_createblack)(var width,var height,var format);
EXT BMAP* F(bmap_createpart)(char* filename,var x,var y,var width,var height);
EXT void F(bmap_remove)(BMAP* bmap);
EXT BMAP* F(bmap_for_entity)(ENTITY*,var frame);
EXT BMAP* F(bmap_for_screen)(BMAP*,var,var);
EXT BMAP* F(bmap_for_buffer)(var mode);
EXT BMAP* F(bmap_for_texture)(char* texname);
EXT void* F(bmap_preload)(BMAP*);
EXT void* F(bmap_purge)(BMAP*);
EXT BMAP* F(bmap_load)(BMAP*,char* filename,var flags);
EXT BMAP* F(bmap_save)(BMAP*,char *filename);
EXT BMAP* F(bmap_to_alpha)(BMAP*,var factor);
EXT BMAP* F(bmap_to_cubemap)(BMAP*);
EXT BMAP* F(bmap_to_mipmap)(BMAP*);
EXT BMAP* F(bmap_to_normals)(BMAP*,var);
EXT BMAP* F(bmap_to_uv)(BMAP*);
EXT BMAP* F(bmap_to_format)(BMAP*,var format);
EXT_var	F(bmap_height)(BMAP*);
EXT_var	F(bmap_width)(BMAP*);
EXT_var	F(bmap_format)(BMAP*);
EXT_var	F(bmap_lock)(BMAP*,var);
EXT_var	F(bmap_unlock)(BMAP*);
EXT_var F(bmap_blit)(BMAP* bDest,BMAP* bSrc,VECTOR* vPos,VECTOR* vSize);
EXT_var F(bmap_blitpart)(BMAP* bDest,BMAP* bSrc,VECTOR* vDestPos,VECTOR* vDestSize,VECTOR* vSrcPos,VECTOR* vSrcSize);
EXT BMAP* F(bmap_fill)(BMAP* bmap,COLOR* color,var alpha);
EXT BMAP* F(bmap_process)(BMAP *bDest,BMAP *bSrc,MATERIAL* mtl);
EXT_var F(bmap_rendertarget)(BMAP* bmap,var num,var face);
EXT_var F(bmap_zbuffer)(BMAP* bmap);
EXT_var F(pixel_for_bmap)(BMAP*,var,var);
EXT_var F(pixel_to_bmap)(BMAP*,var x,var y,var pixel);
EXT_var F(pixel_for_vec)(COLOR*,var,var);
EXT COLOR* F(pixel_to_vec)(COLOR*,var*,var,var pixel);

// multimedia & movies
EXT_var F(cd_play)(var from,var to);
EXT_var F(cd_pause)();
EXT_var F(cd_start)();
EXT_var F(cd_track)();
EXT_var F(media_play)(char* filename,BMAP* target,var volume);
EXT_var F(media_loop)(char* filename,BMAP* target,var volume);
EXT_var F(media_pause)(var handle);
EXT_var F(media_playing)(var handle);
EXT_var F(media_start)(var handle);
EXT_var F(media_stop)(var handle);
EXT_var F(media_tune)(var handle,var volume,var pitch,var balance);

// sound
EXT SOUND* F(snd_create)(char *filename);
EXT_var F(snd_remove)(SOUND*);
EXT_var F(snd_buffer)(SOUND* snd,void** pDesc,void*** ppSample);
EXT_var F(snd_play)(SOUND*,var,var);
EXT_var F(snd_loop)(SOUND*,var,var);
EXT_var F(snd_playing)(var handle);
EXT_var F(snd_pause)(var handle);
EXT_var F(snd_start)(var handle);
EXT_var F(snd_stop)(var handle);
EXT_var F(snd_tune)(var handle,var,var,var);
EXT_var F(snd_add)(var handle,var offset,void* Sample, var length);
EXT_var F(snd_stopall)(var);
EXT_var F(ent_playloop)(ENTITY*,SOUND*,var);
EXT_var F(ent_playloop2)(ENTITY*,SOUND*,var vol,var range);
EXT_var F(ent_playsound)(ENTITY*,SOUND*,var);
EXT_var F(ent_playsound2)(ENTITY*,SOUND*,var vol,var range);

// collision detection
EXT_var F(c_intersect)(VECTOR* min1,VECTOR* max1,VECTOR* vel1,VECTOR* min2,VECTOR* max2,VECTOR* vel2);
EXT_var F(c_content)(VECTOR*,var mode);
EXT_var F(c_scan)(VECTOR*,VECTOR*,VECTOR*,var mode);
EXT_var F(c_trace)(VECTOR*,VECTOR*,var mode);
EXT_var F(c_move)(ENTITY*,VECTOR*,VECTOR*,var mode);
EXT_var F(c_rotate)(ENTITY*,VECTOR*,var mode);
EXT_var F(c_setminmax)(ENTITY*);
EXT_var F(c_updatehull)(ENTITY*,var);
EXT_var F(c_ignore)(var,...);

// effects, particles, materials
EXT MATERIAL* F(mtl_create)();
EXT void F(mtl_remove)(MATERIAL*);
EXT_var F(effect)(EVENT,var,VECTOR*,VECTOR*);
EXT_var F(effect_layer)(EVENT,var,VECTOR*,VECTOR*);
EXT_var F(effect_local)(EVENT,var,VECTOR*,VECTOR*);
EXT void* F(effect_cpy)(MATERIAL* to,MATERIAL* from);
EXT void* F(effect_load)(MATERIAL* mtl,char *filename);
EXT_var F(mat_effect)(float *matrix);

// entity
EXT ENTITY* F(ent_create)(char* filename,VECTOR* position,EVENT);
EXT ENTITY* F(ent_createlocal)(char* filename,VECTOR*,EVENT);
EXT ENTITY* F(ent_createlayer)(char* filename,var flags,var layer);
EXT ENTITY* F(ent_createterrain)(BMAP* bmap,VECTOR* pos,var nx,var ny,var size);
EXT ENTITY* F(ent_next)(ENTITY*);
EXT ENTITY* F(ent_nextlight)(ENTITY*,var n);
EXT_var F(ent_nextvertex)(ENTITY*,VECTOR*);
EXT ENTITY* F(ent_pvs)(var n,var mode);
EXT ENTITY* F(ent_for_name)(char* name);
EXT ENTITY* F(ent_for_file)(char *s);
EXT void* F(ent_mesh)(ENTITY* ent,var num);
EXT void* F(ent_getmesh)(ENTITY* ent,var num,var lod);
EXT_var F(ent_setmesh)(ENTITY* ent,void* mesh,var num,var lod);
EXT_var F(ent_buffers)(ENTITY *e,var n,var lod,void** verts,void** tris,void** attribs);
EXT CONTACT* F(ent_getvertex)(ENTITY *e,CONTACT* c,var num);
EXT CONTACT* F(ent_setvertex)(ENTITY *e,CONTACT* c,var num);
EXT PARTICLE* F(ent_decal)(ENTITY*,BMAP*,var size,var angle);
EXT PARTICLE* F(ent_getdecal)(ENTITY* e,var chunk,var num);
EXT ENTITY* F(ent_clone)(ENTITY*);
EXT ENTITY* F(ent_cloneskin)(ENTITY*);
EXT_var F(ent_morph)(ENTITY*,char *filename);
EXT_var F(ent_morphskin)(ENTITY*,char *filename);
EXT MATERIAL* F(ent_mtlset)(ENTITY*,MATERIAL*,var skin);
EXT BMAP* F(ent_getskin)(ENTITY*,var skin);
EXT BMAP* F(ent_setskin)(ENTITY*,BMAP*,var skin);
EXT_var F(ent_preload)(ENTITY*);
EXT_var F(ent_purge)(ENTITY*);
EXT_var F(ent_reload)(ENTITY*);
EXT_var F(ent_remove)(ENTITY*);
EXT_var F(ent_animate)(ENTITY*,char *scenename,var,var);
EXT_var F(ent_animatefrom)(ENTITY*,ENTITY*,char *scenename,var,var);
EXT_var F(ent_blend)(STRING*,var,var);
EXT_var F(ent_blendframe)(ENTITY*,ENTITY*,char *scenename,var,var);
EXT_var F(ent_blendpose)(ENTITY*,var,var,var);
EXT STRING* F(ent_bonename)(ENTITY*,STRING*,var);
EXT_var F(ent_bonereset_all)(ENTITY*);
EXT_var F(ent_bonereset)(ENTITY*,char *bonename);
EXT_var F(ent_bonereset_branch)(ENTITY*,char *bonename);
EXT_var F(ent_bonerotate)(ENTITY*,char *bonename,VECTOR*);
EXT_var F(ent_bonerotate_parent)(ENTITY*,char *bonename,VECTOR*);
EXT_var F(ent_bonemove)(ENTITY*,char *bonename,VECTOR*);
EXT_var F(ent_bonescale)(ENTITY*,char *bonename,VECTOR*);
EXT long F(ent_bonehandle)(ENTITY*,char *bonename,var index);
EXT long F(ent_boneparent)(ENTITY*,char *bonename,var index);
EXT_var F(ent_fixnormals)(ENTITY*,var);
EXT_var F(ent_type)(ENTITY*);
EXT_var F(ent_status)(ENTITY*,var mode);
EXT_var F(ent_frames)(ENTITY*);
EXT_var F(ent_skins)(ENTITY*);
EXT_var F(ent_bones)(ENTITY*);
EXT_var F(ent_vertices)(ENTITY*);

// pathfinding
EXT_var F(path_create)(ENTITY*,var,var);
EXT_var F(path_set)(ENTITY*,char *name);
EXT_var F(path_next)(ENTITY*);
EXT_var* F(path_getedge)(ENTITY*,var,var,var* skills);
EXT_var* F(path_setedge)(ENTITY*,var,var,var* skills);
EXT_var* F(path_getnode)(ENTITY*,var,VECTOR* position,var* skills);
EXT_var* F(path_setnode)(ENTITY*,var,VECTOR* position,var* skills);
EXT_var	F(path_nextnode)(ENTITY*,var,var);
EXT_var F(path_scan)(ENTITY*,VECTOR* position,ANGLE* direction,VECTOR* sector);
EXT_var F(path_scanpath)(ENTITY*,VECTOR* position,ANGLE* direction,VECTOR* sector);
EXT_var F(path_scannode)(ENTITY*,var number);
EXT_var F(path_length)(ENTITY*);
EXT_var F(path_spline)(ENTITY*,VECTOR* position,var dist);
EXT_var F(region_check)(char* name,VECTOR* vMin, VECTOR* vMax);
EXT_var F(region_create)(char* name,VECTOR* vMin, VECTOR* vMax);
EXT STRING* F(region_find)(STRING* name,VECTOR* pos);
EXT_var F(region_set)(char* name,var mode);
EXT_var F(region_get)(char* name,var num,VECTOR* vMin, VECTOR* vMax);

// file i/o
EXT char* F(file_cpy)(char *name_to,char *name_from);
EXT char* F(file_rename)(char *name_old,char *name_new);
EXT char* F(file_for_screen)(char *name,var number);
EXT long F(file_date)(char *name);
EXT char* F(file_delete)(char *name);
EXT void* F(file_exists)(char *name);
EXT void* F(file_load)(char *name,void* buffer,long* size);
EXT void* F(file_save)(char *name,void* buffer,long size);
EXT_var F(file_open_append)(char *name);
EXT_var F(file_open_game)(char *name);
EXT_var F(file_open_read)(char *name);
EXT_var F(file_open_write)(char *name);
EXT_var F(file_close)(var handle);
EXT_var F(file_length)(var handle);
EXT_var F(file_find)(var handle,char *str);
EXT_var F(file_seek)(var handle,var offset,var mode);
EXT_var F(file_asc_read)(var handle);
EXT_var F(file_asc_write)(var handle,var);
EXT_var F(file_chr_read)(var handle,STRING*);
EXT_var F(file_str_read)(var handle,STRING*);
EXT_var F(file_str_readto)(var handle,STRING *s,char *delimit,var length);
EXT_var F(file_str_readtow)(var handle,STRING *s,char *delimit,var length);
EXT_var F(file_str_write)(var handle,char*);
EXT_var F(file_str_writeto)(var handle,char*,var length);
EXT_var F(file_var_read)(var handle);
EXT_var F(file_var_write)(var handle,var);

// keys
EXT_var F(key_for_str)(char*);
EXT STRING* F(str_for_key)(STRING*,var);
EXT_var F(key_pressed)(var);
EXT_var F(key_set)(var,EVENT);

// game & video
EXT_var F(level_load)(char *filename);
EXT void F(level_mark)();
EXT void F(level_free)();
EXT_var F(game_save)(char *filename,var,var);
EXT_var F(game_load)(char *filename,var);

EXT long F(sys_active)(char *title);
EXT_var F(sys_exit)(char *message);
EXT_var F(sys_message)(char *message);
EXT_var F(sys_metrics)(var);
EXT_var F(sys_record)(char *filename,var mode);
EXT_var F(sys_replay)(char *filename);
EXT_var F(sys_trial)(char* section,char *name,var days); 
EXT_var F(sys_setstr)(char* section,char *name,char* str); 
EXT STRING* F(sys_getstr)(char* section,char *name,char* str); 
EXT_var F(sys_setvar)(char* section,char *name,var val); 
EXT_var F(sys_getvar)(char* section,char *name); 

EXT_var F(video_set)(var,var,var,var);
EXT_var F(video_switch)(var,var,var);
EXT_var F(video_window)(VECTOR*,VECTOR*,var,char *title);
EXT_var F(video_border)(BMAP* border,var x,var y,var dx,var dy);

// panels, views, text
EXT PANEL* F(pan_create)(char* content,var layer);
EXT_var F(pan_remove)(PANEL*);
EXT_var F(pan_setbmap)(PANEL*,var type,var number,BMAP* bmap);
EXT_var F(pan_setcolor)(PANEL*,var type,var number,COLOR*);
EXT_var F(pan_setevent)(PANEL*,var type,var number,EVENT event);
EXT_var F(pan_setpos)(PANEL*,var type,var number,VECTOR* xy);
EXT_var F(pan_getpos)(PANEL*,var type,var number,VECTOR* xy);
EXT_var F(pan_setvar)(PANEL*,var type,var number,var* v);
EXT_var F(pan_setbutton)(PANEL* p,var num,var type,var x,var y,
    BMAP* bmapOn,BMAP* bmapOff,BMAP* bmapOver,BMAP* bmapOverOff,
    void* functionClick,void* functionLeave,void* functionOver);
EXT_var F(pan_setdigits)(PANEL* p,var num,var x,var y,
    char* format,FONT* font,var factor,var* pv);
EXT_var F(pan_setneedle)(PANEL* p,var num,var x,var y,
    BMAP* bmap,var cx,var cy,var angle,var min,var max,var* pv);
EXT_var F(pan_setslider)(PANEL* p,var num,var x,var y,
    BMAP* bmapBg,BMAP* bmapKnob,var min,var max,var* pv);
EXT_var F(pan_setstring)(PANEL* p,var num,var x,var y,
    FONT* font,char* string);
EXT_var F(pan_setwindow)(PANEL* p,var num,var x,var y,
    var dx,var dy,BMAP* bmap,var* px,var* py);
EXT_var F(digits_set)(PANEL*,var number,var* digit);
EXT_var F(button_state)(PANEL*,var number,var state);
EXT_var F(layer_sort)(void *element,var layer);

EXT TEXT* F(txt_create)(var strings,var layer);
EXT void F(txt_remove)(TEXT*);
EXT_var F(txt_for_dir)(TEXT*,char *path);
EXT_var F(txt_sort)(TEXT*);
EXT_var F(txt_load)(TEXT*,char *filename);
EXT_var F(txt_loadw)(TEXT*,char *filename);
EXT_var F(txt_addstring)(TEXT *t,char *s);
EXT_var F(txt_setinvisible)(TEXT*,var);
EXT_var F(txt_setvisible)(TEXT*,var);
EXT STRING* F(txt_str)(TEXT*,int n);

EXT FONT* F(font_create)(char* content);
EXT void F(font_remove)(FONT*);

EXT VIEW* F(view_create)(var layer);
EXT_var F(view_check)(VIEW* view,VECTOR* vMin,VECTOR* vMax);
EXT_var F(view_to_light)(VIEW* view,var num,var mode);
EXT float* F(view_to_matrix)(VIEW* view,float *matView,float *matProj);
EXT float* F(view_to_split)(VIEW* view,var split1,var split2,VIEW* split,float* matSplit);

// draw
EXT void* F(draw_begin)();
EXT_var F(draw_line)(VECTOR* xy,COLOR*,var alpha);
EXT_var F(draw_line3d)(VECTOR* xyz,COLOR*,var alpha);
EXT_var F(draw_box3d)(VECTOR* vMin,VECTOR* vMax,COLOR*,var alpha);
EXT_var F(draw_obj)(void* ptr);
EXT_var F(draw_point3d)(VECTOR* vPos,COLOR*,var alpha,var size);
EXT_var F(draw_quad)(BMAP* bmap,VECTOR* vPos,VECTOR* vOffs,
    VECTOR* vSize,VECTOR* vScale,COLOR* vColor,var alpha,var angle);
EXT_var F(draw_text)(char* text,var,var,COLOR*);
EXT_var F(draw_textmode)(char* fontname,var,var,var);

// network
EXT_var F(proc_client)(ENTITY*,EVENT);
EXT_var F(proc_local)(ENTITY*,EVENT);
EXT_var F(send_data_to)(ENTITY*,void* buffer,var size);
EXT_var F(send_data_id)(var client_id,void* buffer,var size);
EXT_var F(send_skill)(var* skill,var mode);
EXT_var F(send_skill_to)(ENTITY*,var* skill,var mode);
EXT_var F(send_skill_id)(var client_id,var* skill,var mode);
EXT_var F(send_string)(STRING*);
EXT_var F(send_string_to)(ENTITY*,STRING*);
EXT_var F(send_string_id)(var client_id,STRING*);
EXT_var F(send_var)(void*);
EXT_var F(send_var_to)(ENTITY*,void*);
EXT_var F(send_var_id)(var client_id,void*);
EXT void F(session_close)();
EXT_var F(session_connect)(char* sessionname,char *hostname);
EXT_var F(session_open)(char* sessionname);
EXT_var F(client_drop)(char* name);
EXT_var F(client_drop_id)(var client_id);
EXT_var F(client_find)(var num);
EXT_var F(ent_sendnow)(ENTITY*);

EXT_var F(socket_connect)(char *IP,var port,var mode);
EXT_var F(socket_select)(var num);
EXT_var F(socket_receive)(void* buffer,var size);
EXT_var F(socket_send)(void* buffer,var size);

// diagnostics
EXT_var F(beep)();
EXT_var F(diag)(char *text);
EXT_var F(diag_var)(char *format,var);
EXT_var F(diag_frame)(var *v);	// log this var every frame
EXT_var F(diag_status)();
EXT_var F(error)(char *text);
EXT_var F(timer)();		// high precision timer
EXT double F(dtimer)();	// high precision timer
EXT_var F(breaks)();		// for internal tests

// input/output
EXT_var F(port_in)(var port);
EXT_var F(port_out)(var port,var data);
EXT_var F(wiimote_handle)(var num);

// misc
EXT_var F(exec)(char* program,char *cmdline);
EXT_var F(exec_wait)(char* program,char *cmdline);
EXT_var F(proc_kill)(var);
EXT_var F(proc_kill2)(void* code,ENTITY* ent);
EXT_var F(proc_status)(void* code);	// 1 = function running, 0 = not running
EXT_var F(proc_status2)(void* code,ENTITY* ent);	
EXT_var F(execute)(char *command);
EXT void* F(var_for_name)(char* name);
EXT void* F(ptr_first)(void* object);
EXT void* F(ptr_remove)(void* object);
EXT void* F(ptr_for_handle)(var handle);
EXT_var F(handle)(void* object);
EXT void* F(sys_malloc)(long size);
EXT void* F(sys_nxalloc)(long size);
EXT void F(sys_free)(void* ptr);
EXT void* F(sys_marker)(char* mark);

////////////////////////////////////////////////////////////////////////////
// conversion and utility functions for the DLL interface

EXT char* F(_chr)(STRING*);	
// converts a string to a char

EXT STRING*	F(_str)(char*);	
// char* -> temporary STRING*, for passing char[] constants to functions only 

EXT VECTOR*	F(_vec)(float x,float y,float z); 
// float,float,float -> temporary VECTOR*, for passing vector constants to functions only 

EXT_var F(add_buffer)(char* name,void* buffer,long size);	
// add a named buffer for game files

EXT_var F(add_folder)(char* pathname);		
// add a path for game files

EXT_var F(add_resource)(char* content);	
// add a WRS resource from a file name or WRS buffer content

EXT_var F(add_new)();	
// removes all named buffer, paths, and resources

EXT_var F(add_struct)(void* data,long size);	
// add a memory area to be saved

EXT long F(engine_getobj)(char *name);
// returns the address of any script object with the given name
// if the object was a pointer, ev->isPointer is set

EXT void* F(engine_getvar)(char *name,long* type);
// returns the address of any lite-C object with the given name
// type is set to the type of the variable:
#define VAR_STRUCT	0
#define VAR_CHAR	1
#define VAR_SHORT	2
#define VAR_FIXED	3
#define VAR_LONG	4
#define VAR_FLOAT	5
#define VAR_DOUBLE	7
#define VAR_POINTER	16	// added if it's a pointer	

EXT long F(engine_getvarinfo)(void* address,char *name,char *structname,long *offset);
// returns the type of a variable at the given address,
// and sets the variable name, and the struct name and offset if
// it's a part of a struct

EXT long F(engine_getfunc)(char *name);
// returns the address of an engine function that is not yet listed in afuncs.h

EXT long F(engine_getscript)(char *name);
// returns the address of a user defined lite-C or C-Script function or action

EXT long F(engine_getscriptinfo)(void* address,char **name);
// sets the name pointer to the name of the script function at the given address.

EXT long F(engine_gettaskinfo)(long num,char **name,ENTITY **me);
// returns the address of the running task with the given number,
// and sets the function name pointer and the me pointer of that task

EXT_var F(engine_callname4)(char *name,long p1,long p2,long p3,long p4);
EXT_var F(engine_callscript4)(long address,long p1,long p2,long p3,long p4);
// obsolete functions for calling A4 WDL code

EXT_var F(engine_debugposition)(char **scriptname,long *offset,long *line);
// gives the last position of the source debugger
// scriptname - set to the name of the current script file,
//              or NULL if no debugging is in process
// offset - set to the offset within the file, in bytes
// line - set to the line number within the file
// returns - the result of the last instruction

EXT_var F(engine_debugbreakpoint)(char *scriptname,long line, long on);
// sets or resets a breakpoint
// scriptname - name of the script file.
// line - line number of the breakpoint. 
// on - 0 to reset, 1 to set the breakpoint
// returns - 0 if the line does not contain a valid instruction,
// 1 for pure mode and 2 for window mode

EXT long F(engine_debugstep)(long mode);
// For controlling the source debugger in window mode.
// mode = 2 -> Step over
// mode = 1 -> Step into
// mode = 0 -> Cancel debugging, run until next breakpoint is hit 
// mode = -1 -> Cancel debugging and ignore all further breakpoints.

EXT long F(engine_status)(long code);
// returns 4 when variables are initialized

#endif

// only available for plugin DLLs ///////////////////////////////////////////
#ifndef afuncs_dll_h
#define afuncs_dll_h

EXT long engine_bind(void);	
// to be called in DllMain 

EXT_var engine_callscript(long address,long p1=0,long p2=0,long p3=0,long p4=0);
// calls a user-defined C-Script function with given address
// parameters can be a var, an array, or a pointer to a WDL object

// not available for plugin DLLs ////////////////////////////////////////////

EXT ENGINE_VARS* engine_open(char* commandline,DWORD callback = 0);	
// open the engine, pass an optional command line with a model, level, or script.
// When using debugging, make sure to create the exe with the linker option
// "Image is not compatible with DEP (/NXCOMPAT:NO)" (VC++ 2008)

EXT long engine_frame(void);	
// render a frame

EXT long engine_close(void);	
// close the engine, release all resources, return exit code

#endif
