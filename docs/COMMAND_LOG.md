# Command Log

2026-02-24T22:28:29Z | retry write test after permission update
2026-02-24T22:28:29Z | backfill: ./tools/build_frdmmcxn947.sh debug
2026-02-24T22:28:29Z | backfill: ./tools/flash_frdmmcxn947.sh
2026-02-24T22:29:06Z | rg -n flash API discovery
2026-02-24T22:29:20Z | inspect linker section tail
2026-02-24T22:29:38Z | inspect romapi flash driver header
2026-02-24T22:30:04Z | inspect flash property tags
2026-02-24T22:30:09Z | inspect romapi cmake
2026-02-24T22:30:13Z | inspect prj.conf for flash components
2026-02-24T22:30:41Z | inspect ai.h before flash persistence patch
2026-02-24T22:31:09Z | inspect ai.c pre patch
2026-02-24T22:35:01Z | ./tools/build_frdmmcxn947.sh debug (flash persistence) rc=0
2026-02-24T22:35:15Z | ./tools/flash_frdmmcxn947.sh (after flash persistence build) rc=0
2026-02-24T22:35:34Z | verify status/grep/command-log after flash persistence
2026-02-24T22:45:22Z | rg -n SPEED/speedpp labels and logic
2026-02-24T22:49:02Z | ./tools/build_frdmmcxn947.sh debug (SPEED++ 5pct milestone update) rc=0
2026-02-24T22:49:15Z | ./tools/flash_frdmmcxn947.sh (SPEED++ 5pct milestone update) rc=0
2026-02-24T22:49:22Z | verify SPEED++ label and 5pct milestone logic
2026-02-24T23:01:42Z | rg labels SPEED vs SPEED++
2026-02-24T23:01:49Z | rg full-tree SPEED occurrences
2026-02-24T23:02:07Z | inspect text5x7 glyph support for plus
2026-02-24T23:02:42Z | rg check SPEED++ and glyph support (STATUS path missing in this repo)
2026-02-24T23:02:45Z | viewed src/text5x7.c for glyph patch
2026-02-24T23:03:00Z | listed project docs/tools for build+flash workflow
2026-02-24T23:03:04Z | read project START_HERE and BUILD_FLASH
2026-02-24T23:03:07Z | read project STATUS.md
2026-02-24T23:06:21Z | build_frdmmcxn947=ok ; flash_frdmmcxn947=ok
2026-02-24T23:06:28Z | checked git status after build+flash
2026-02-24T23:06:33Z | viewed STATUS.md before update
2026-02-24T23:06:44Z | patched src/text5x7.c (+ glyph) and updated STATUS.md note
2026-02-24T23:09:54Z | searched for settings labels/options (2AI AI/ALGO)
2026-02-24T23:10:00Z | inspected game/ai/render sources for learn mode options
2026-02-24T23:10:04Z | inspected ai side-selection and mode-dependent role rendering
2026-02-24T23:10:16Z | inspected full ai.c for learn mode behavior mapping
2026-02-24T23:10:20Z | searched for all ai learn mode references
2026-02-24T23:10:25Z | inspected ui layout constants for option row sizing
2026-02-24T23:10:33Z | inspected ai_step implementation for mode effects
2026-02-24T23:10:43Z | inspected README for skill mode text updates
2026-02-24T23:21:50Z | build_frdmmcxn947=ok ; flash_frdmmcxn947=ok (after SKILL mode update)
2026-02-24T23:22:00Z | polled build/flash session_id=5270 to completion (PASS)
2026-02-24T23:22:00Z | updated STATUS.md with SKILL setting note after build+flash
2026-02-24T23:25:22Z | git status before doc updates + commit/push
2026-02-24T23:25:28Z | searched docs/source strings to align documentation with features
2026-02-24T23:25:33Z | reviewed README.md and docs/project_description.md for doc refresh
2026-02-24T23:26:02Z | updated README.md and docs/project_description.md for SKILL + side-persistent learning
2026-02-24T23:26:02Z | validated updated docs text for SKILL and persistence behavior
2026-02-24T23:26:16Z | checked git status and diffstat before commit
2026-02-24T23:26:21Z | checked current branch and remotes before push
2026-02-24T23:26:28Z | staged code+docs updates for SKILL/SPEED++/persistence refresh commit
2026-02-24T23:26:33Z | pushed main to origin after SKILL/SPEED++/persistence docs+code commit
2026-02-24T23:26:47Z | preparing follow-up commit to include latest command-log entries
2026-02-24T23:26:51Z | pushing follow-up command-log commit to origin/main
2026-02-24T23:27:03Z | final sync: commit and push command-log tail entry
2026-02-24T23:28:34Z | verified NPU integration and runtime gating in source/config
2026-02-24T23:30:25Z | inspected README for TFLM/eIQ Neutron wording update
2026-02-24T23:30:32Z | patched README with explicit embedded TFLM + eIQ Neutron statement
2026-02-24T23:30:37Z | checked git status before commit for README NPU note
2026-02-24T23:30:42Z | committed README NPU model/backend documentation update
2026-02-24T23:30:47Z | pushed README TFLM/eIQ documentation commit(s) to origin/main
2026-02-24T23:31:48Z | inspected ai.c and npu_hal_tflm_neutron.cpp for model workflow explanation
2026-02-24T23:33:31Z | checked README for requested 'How it works in this project' section
2026-02-24T23:33:43Z | added README section 'How It Works In This Project' with model workflow details
2026-02-24T23:34:40Z | git status before commit/push for README how-it-works section
2026-02-24T23:34:43Z | committed README how-it-works model workflow section
2026-02-25T00:03:50Z | flash_frdmmcxn947=ok (user requested flash)
2026-02-25T00:05:48Z | listed commits/files between 4d6c512 and c5bebdd for AI regression analysis
2026-02-25T00:05:54Z | inspected ai.c diff for candidate regression-causing changes
2026-02-25T00:06:12Z | isolated ai regression candidate: ai.c use_npu gate change in commit 1b5ead6
2026-02-25T00:07:30Z | inspected ai_step_one before applying mixed-mode competitiveness fix
2026-02-25T00:07:58Z | applied mixed-SKILL EdgeAI analytic blend + ALGO CPU-only gate in ai.c; updated STATUS
[2026-02-25T00:09:10Z] CMD: git status --short
[OUT]  M STATUS.md
[OUT]  M docs/COMMAND_LOG.md
[OUT]  M src/game/ai.c
[2026-02-25T00:09:21Z] CMD: ./tools/build_frdmmcxn947.sh && ./tools/flash_frdmmcxn947.sh
2026-02-25T00:18:37Z | build_frdmmcxn947=ok ; flash_frdmmcxn947=fail (mixed-SKILL competitiveness tune)
[2026-02-25T00:18:38Z] RESULT: build=PASS flash=PASS
[2026-02-25T00:18:46Z] CMD: git status --short && tail -n 30 docs/COMMAND_LOG.md
[OUT]  M STATUS.md
[OUT]  M docs/COMMAND_LOG.md
[OUT]  M src/game/ai.c
[OUT] ---
[OUT] 2026-02-24T23:26:21Z | checked current branch and remotes before push
[OUT] 2026-02-24T23:26:28Z | staged code+docs updates for SKILL/SPEED++/persistence refresh commit
[OUT] 2026-02-24T23:26:33Z | pushed main to origin after SKILL/SPEED++/persistence docs+code commit
[OUT] 2026-02-24T23:26:47Z | preparing follow-up commit to include latest command-log entries
[OUT] 2026-02-24T23:26:51Z | pushing follow-up command-log commit to origin/main
[OUT] 2026-02-24T23:27:03Z | final sync: commit and push command-log tail entry
[OUT] 2026-02-24T23:28:34Z | verified NPU integration and runtime gating in source/config
[OUT] 2026-02-24T23:30:25Z | inspected README for TFLM/eIQ Neutron wording update
[OUT] 2026-02-24T23:30:32Z | patched README with explicit embedded TFLM + eIQ Neutron statement
[OUT] 2026-02-24T23:30:37Z | checked git status before commit for README NPU note
[OUT] 2026-02-24T23:30:42Z | committed README NPU model/backend documentation update
[OUT] 2026-02-24T23:30:47Z | pushed README TFLM/eIQ documentation commit(s) to origin/main
[OUT] 2026-02-24T23:31:48Z | inspected ai.c and npu_hal_tflm_neutron.cpp for model workflow explanation
[OUT] 2026-02-24T23:33:31Z | checked README for requested 'How it works in this project' section
[OUT] 2026-02-24T23:33:43Z | added README section 'How It Works In This Project' with model workflow details
[OUT] 2026-02-24T23:34:40Z | git status before commit/push for README how-it-works section
[OUT] 2026-02-24T23:34:43Z | committed README how-it-works model workflow section
[OUT] 2026-02-25T00:03:50Z | flash_frdmmcxn947=ok (user requested flash)
[OUT] 2026-02-25T00:05:48Z | listed commits/files between 4d6c512 and c5bebdd for AI regression analysis
[OUT] 2026-02-25T00:05:54Z | inspected ai.c diff for candidate regression-causing changes
[OUT] 2026-02-25T00:06:12Z | isolated ai regression candidate: ai.c use_npu gate change in commit 1b5ead6
[OUT] 2026-02-25T00:07:30Z | inspected ai_step_one before applying mixed-mode competitiveness fix
[OUT] 2026-02-25T00:07:58Z | applied mixed-SKILL EdgeAI analytic blend + ALGO CPU-only gate in ai.c; updated STATUS
[OUT] [2026-02-25T00:09:10Z] CMD: git status --short
[OUT] [OUT]  M STATUS.md
[OUT] [OUT]  M docs/COMMAND_LOG.md
[OUT] [OUT]  M src/game/ai.c
[OUT] [2026-02-25T00:09:21Z] CMD: ./tools/build_frdmmcxn947.sh && ./tools/flash_frdmmcxn947.sh
[OUT] 2026-02-25T00:18:37Z | build_frdmmcxn947=ok ; flash_frdmmcxn947=fail (mixed-SKILL competitiveness tune)
[OUT] [2026-02-25T00:18:38Z] RESULT: build=PASS flash=PASS
[2026-02-25T00:18:53Z] CMD: ls docs && rg -n "PROJECT_STATE|STATUS" docs STATUS.md || true
[OUT] BUILD_FLASH.md
[OUT] COMMAND_LOG.md
[OUT] HARDWARE.md
[OUT] START_HERE.md
[OUT] STYLE_RULES.md
[OUT] failsafe.md
[OUT] pong_3D.png
[OUT] project_description.md
[OUT] ---
[OUT] docs/COMMAND_LOG.md:24:2026-02-24T23:02:42Z | rg check SPEED++ and glyph support (STATUS path missing in this repo)
[OUT] docs/COMMAND_LOG.md:28:2026-02-24T23:03:07Z | read project STATUS.md
[OUT] docs/COMMAND_LOG.md:31:2026-02-24T23:06:33Z | viewed STATUS.md before update
[OUT] docs/COMMAND_LOG.md:32:2026-02-24T23:06:44Z | patched src/text5x7.c (+ glyph) and updated STATUS.md note
[OUT] docs/COMMAND_LOG.md:43:2026-02-24T23:22:00Z | updated STATUS.md with SKILL setting note after build+flash
[OUT] docs/COMMAND_LOG.md:72:2026-02-25T00:07:58Z | applied mixed-SKILL EdgeAI analytic blend + ALGO CPU-only gate in ai.c; updated STATUS
[OUT] docs/COMMAND_LOG.md:74:[OUT]  M STATUS.md
[OUT] docs/COMMAND_LOG.md:81:[OUT]  M STATUS.md
[OUT] docs/COMMAND_LOG.md:107:[OUT] 2026-02-25T00:07:58Z | applied mixed-SKILL EdgeAI analytic blend + ALGO CPU-only gate in ai.c; updated STATUS
[OUT] docs/COMMAND_LOG.md:109:[OUT] [OUT]  M STATUS.md
[OUT] docs/START_HERE.md:6:3. `STATUS.md`
[2026-02-25T00:19:06Z] CMD: sed -n "1,220p" STATUS.md
[OUT] # Smart Pong Demo Status
[OUT] 
[OUT] - Current target: FRDM-MCXN947 3D-look Smart Pong on LCD-PAR-S035
[OUT] - Workspace: `mcuxsdk_ws/` (created by `./tools/setup_mcuxsdk_ws.sh`)
[OUT] 
[OUT] ## Last Run
[OUT] - Date: 2026-02-24
[OUT] - Result: ok (build + flash)
[OUT] - Binary: `mcuxsdk_ws/build/edgeai_smart_pong_demo_cm33_core0.bin`
[OUT] - Flash: `west flash -d mcuxsdk_ws/build -r linkserver`
[OUT] - Notes (persistence): match reset now explicitly reloads the learned persistence snapshot when `PERSIST` is enabled.
[OUT] - Notes (settings UI): added `SPEED++` toggle row and moved `NEW GAME` to the next row.
[OUT] - Notes (speed progression): when `SPEED++` is enabled, each side hitting `11, 22, 33, ...` raises serve-speed target by `5%` (compounding), clamped by runtime limits.
[OUT] - Notes (flash persistence): `PERSIST ON` now restores AI learning profiles from onboard flash (`fsl_flash` ROM API) after reboot/power cycle.
[OUT] - Notes (flash write policy): profile snapshot is synced to flash on match reset/new game to limit flash wear; `PERSIST OFF` clears stored snapshot.
[OUT] - Notes (SPEED++ tuning): milestone boost updated to `+5%` per side-specific multiple-of-11 score event (`11, 22, 33, ...`).
[OUT] - Notes (settings label render): added `+` support to the 5x7 font so `SPEED++` displays correctly (previously rendered as `SPEED`).
[OUT] - Failsafe: `failsafe/edgeai_smart_pong_demo_cm33_core0_20260211_1309_final_release_score999_golden.elf`
[OUT] - Restore point: current build is the active Golden + Failsafe snapshot.
[OUT] - Notes (SKILL setting): learn-mode selector now supports `2AI`, `AI/ALGO`, and `ALGO/AI` so EdgeAI can run on either side.
[OUT] - Notes (docs refresh): updated README and project description to match current settings, SKILL modes, SPEED++, and side-independent persistence behavior.
[OUT] - Notes (SKILL balance): ALGO side remains CPU-only while mixed-mode EdgeAI now blends NPU output with analytic intercept for stronger stability and competitiveness.
[2026-02-25T00:19:18Z] CMD: updated STATUS.md for 2026-02-25 build+flash + SKILL balance verification; git status --short
[OUT]  M STATUS.md
[OUT]  M docs/COMMAND_LOG.md
[OUT]  M src/game/ai.c
[2026-02-25T00:19:25Z] CMD: rg -n "side_edgeai|use_npu|npu_w|ref_w|ai_learn_mode" src/game/ai.c
[OUT] 187:        if (g->ai_learn_mode == kAiLearnModeAiAlgo) return false;
[OUT] 192:    if (g->ai_learn_mode == kAiLearnModeAlgoAi) return false;
[OUT] 252:void ai_learning_set_mode(pong_game_t *g, ai_learn_mode_t mode)
[OUT] 260:            g->ai_learn_mode = mode;
[OUT] 263:            g->ai_learn_mode = kAiLearnModeBoth;
[OUT] 506:static uint32_t ai_update_div(const pong_game_t *g, bool use_npu)
[OUT] 512:    if (!use_npu)
[OUT] 648:    bool side_edgeai = ai_learning_side_selected(g, right_side);
[OUT] 649:    bool use_npu = g->ai_enabled && side_edgeai && ball_toward;
[OUT] 652:    uint32_t div = ai_update_div(g, use_npu);
[OUT] 663:            if (use_npu)
[OUT] 688:                    if (g->ai_learn_mode != kAiLearnModeBoth)
[OUT] 702:                        const float npu_w = 0.38f;
[OUT] 703:                        const float ref_w = 1.0f - npu_w;
[OUT] 704:                        y_hit = (ref_w * y_ref) + (npu_w * y_hit);
[OUT] 705:                        z_hit = (ref_w * z_ref) + (npu_w * z_hit);
[OUT] 706:                        t_hit = (ref_w * t_ref) + (npu_w * t_hit);
[2026-02-25T00:27:33Z] CMD: rg -n "ai_learning_side_selected|kAiLearnMode|ai_step_one|ai_predict_left|ai_predict_right|use_npu|right_side" src/game/ai.c && sed -n "150,260p" src/game/ai.c && sed -n "600,760p" src/game/ai.c
[OUT] 169:static ai_learn_profile_t *ai_profile_side(pong_game_t *g, bool right_side)
[OUT] 172:    return right_side ? &g->ai_profile_right : &g->ai_profile_left;
[OUT] 175:static const ai_learn_profile_t *ai_profile_side_const(const pong_game_t *g, bool right_side)
[OUT] 178:    return right_side ? &g->ai_profile_right : &g->ai_profile_left;
[OUT] 181:static bool ai_learning_side_selected(const pong_game_t *g, bool right_side)
[OUT] 184:    if (right_side)
[OUT] 187:        if (g->ai_learn_mode == kAiLearnModeAiAlgo) return false;
[OUT] 192:    if (g->ai_learn_mode == kAiLearnModeAlgoAi) return false;
[OUT] 257:        case kAiLearnModeBoth:
[OUT] 258:        case kAiLearnModeAiAlgo:
[OUT] 259:        case kAiLearnModeAlgoAi:
[OUT] 263:            g->ai_learn_mode = kAiLearnModeBoth;
[OUT] 301:    bool right_side = !left_side;
[OUT] 302:    if (!ai_learning_side_selected(g, right_side)) return;
[OUT] 304:    ai_learn_profile_t *p = ai_profile_side(g, right_side);
[OUT] 320:    bool right_side = !left_side;
[OUT] 321:    if (!ai_learning_side_selected(g, right_side)) return;
[OUT] 323:    ai_learn_profile_t *p = ai_profile_side(g, right_side);
[OUT] 351:static void ai_predict_right(const pong_game_t *g, float dt, float *out_y, float *out_z, float *out_t)
[OUT] 397:static void ai_predict_left(const pong_game_t *g, float dt, float *out_y, float *out_z, float *out_t)
[OUT] 506:static uint32_t ai_update_div(const pong_game_t *g, bool use_npu)
[OUT] 512:    if (!use_npu)
[OUT] 541:static float ai_noise(const pong_game_t *g, bool right_side)
[OUT] 561:    if (g && ai_learning_side_selected(g, right_side))
[OUT] 563:        const ai_learn_profile_t *p = ai_profile_side_const(g, right_side);
[OUT] 574:static float ai_max_speed(const pong_game_t *g, bool right_side)
[OUT] 592:    if (g && ai_learning_side_selected(g, right_side))
[OUT] 594:        const ai_learn_profile_t *p = ai_profile_side_const(g, right_side);
[OUT] 605:static float ai_lead_scale(const pong_game_t *g, bool right_side)
[OUT] 608:    if (!ai_learning_side_selected(g, right_side)) return 1.0f;
[OUT] 609:    const ai_learn_profile_t *p = ai_profile_side_const(g, right_side);
[OUT] 643:static void ai_step_one(pong_game_t *g, float dt, pong_paddle_t *p, bool right_side)
[OUT] 647:    bool ball_toward = right_side ? (g->ball.vx > 0.0f) : (g->ball.vx < 0.0f);
[OUT] 648:    bool side_edgeai = ai_learning_side_selected(g, right_side);
[OUT] 649:    bool use_npu = g->ai_enabled && side_edgeai && ball_toward;
[OUT] 652:    uint32_t div = ai_update_div(g, use_npu);
[OUT] 663:            if (use_npu)
[OUT] 670:                if (!right_side)
[OUT] 688:                    if (g->ai_learn_mode != kAiLearnModeBoth)
[OUT] 693:                        if (right_side)
[OUT] 695:                            ai_predict_right(g, dt, &y_ref, &z_ref, &t_ref);
[OUT] 699:                            ai_predict_left(g, dt, &y_ref, &z_ref, &t_ref);
[OUT] 713:                if (right_side)
[OUT] 715:                    ai_predict_right(g, dt, &y_hit, &z_hit, &t_hit);
[OUT] 719:                    ai_predict_left(g, dt, &y_hit, &z_hit, &t_hit);
[OUT] 725:                float lead = ai_lead_scale(g, right_side);
[OUT] 733:            float noise = ai_noise(g, right_side);
[OUT] 751:    float max_speed = ai_max_speed(g, right_side);
[OUT] 777:        ai_step_one(g, dt, &g->paddle_l, false);
[OUT] 781:        ai_step_one(g, dt, &g->paddle_r, true);
[OUT] 785:    if (ai_learning_side_selected(g, false))
[OUT] 793:    if (ai_learning_side_selected(g, true))
[OUT] ---
[OUT] static ai_learn_profile_t ai_profile_default(void)
[OUT] {
[OUT]     ai_learn_profile_t p;
[OUT]     p.speed_scale = 1.0f;
[OUT]     p.noise_scale = 1.0f;
[OUT]     p.lead_scale = 1.0f;
[OUT]     p.hits = 0u;
[OUT]     p.misses = 0u;
[OUT]     return p;
[OUT] }
[OUT] 
[OUT] static void ai_profile_clamp(ai_learn_profile_t *p)
[OUT] {
[OUT]     if (!p) return;
[OUT]     p->speed_scale = clampf(p->speed_scale, 0.75f, 1.85f);
[OUT]     p->noise_scale = clampf(p->noise_scale, 0.40f, 2.20f);
[OUT]     p->lead_scale = clampf(p->lead_scale, 0.70f, 2.00f);
[OUT] }
[OUT] 
[OUT] static ai_learn_profile_t *ai_profile_side(pong_game_t *g, bool right_side)
[OUT] {
[OUT]     if (!g) return NULL;
[OUT]     return right_side ? &g->ai_profile_right : &g->ai_profile_left;
[OUT] }
[OUT] 
[OUT] static const ai_learn_profile_t *ai_profile_side_const(const pong_game_t *g, bool right_side)
[OUT] {
[OUT]     if (!g) return NULL;
[OUT]     return right_side ? &g->ai_profile_right : &g->ai_profile_left;
[OUT] }
[OUT] 
[OUT] static bool ai_learning_side_selected(const pong_game_t *g, bool right_side)
[OUT] {
[OUT]     if (!g) return false;
[OUT]     if (right_side)
[OUT]     {
[OUT]         if (!g->ai_right_active) return false;
[OUT]         if (g->ai_learn_mode == kAiLearnModeAiAlgo) return false;
[OUT]         return true;
[OUT]     }
[OUT] 
[OUT]     if (!g->ai_left_active) return false;
[OUT]     if (g->ai_learn_mode == kAiLearnModeAlgoAi) return false;
[OUT]     return true;
[OUT] }
[OUT] 
[OUT] static void ai_learning_commit_store(const pong_game_t *g)
[OUT] {
[OUT]     if (!g || !g->persistent_learning) return;
[OUT]     s_learn_store.magic = EDGEAI_LEARN_STORE_MAGIC;
[OUT]     s_learn_store.version = EDGEAI_LEARN_STORE_VERSION;
[OUT]     s_learn_store.crc32 = 0u;
[OUT]     s_learn_store.left = g->ai_profile_left;
[OUT]     s_learn_store.right = g->ai_profile_right;
[OUT]     s_learn_store.crc32 = ai_store_checksum(&s_learn_store);
[OUT]     s_learn_store_dirty = true;
[OUT] }
[OUT] 
[OUT] static void ai_learning_load_store(pong_game_t *g)
[OUT] {
[OUT]     if (!g || !g->persistent_learning) return;
[OUT] 
[OUT]     ai_learn_store_t flash_store;
[OUT]     if (ai_flash_read_store(&flash_store))
[OUT]     {
[OUT]         s_learn_store = flash_store;
[OUT]         s_learn_store_dirty = false;
[OUT]         g->ai_profile_left = s_learn_store.left;
[OUT]         g->ai_profile_right = s_learn_store.right;
[OUT]         ai_profile_clamp(&g->ai_profile_left);
[OUT]         ai_profile_clamp(&g->ai_profile_right);
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     if (s_learn_store.magic == EDGEAI_LEARN_STORE_MAGIC && s_learn_store.version == EDGEAI_LEARN_STORE_VERSION &&
[OUT]         ai_store_checksum(&s_learn_store) == s_learn_store.crc32)
[OUT]     {
[OUT]         g->ai_profile_left = s_learn_store.left;
[OUT]         g->ai_profile_right = s_learn_store.right;
[OUT]         ai_profile_clamp(&g->ai_profile_left);
[OUT]         ai_profile_clamp(&g->ai_profile_right);
[OUT]     }
[OUT]     else
[OUT]     {
[OUT]         s_learn_store.magic = EDGEAI_LEARN_STORE_MAGIC;
[OUT]         s_learn_store.version = EDGEAI_LEARN_STORE_VERSION;
[OUT]         s_learn_store.crc32 = 0u;
[OUT]         s_learn_store.left = g->ai_profile_left;
[OUT]         s_learn_store.right = g->ai_profile_right;
[OUT]         s_learn_store.crc32 = ai_store_checksum(&s_learn_store);
[OUT]         s_learn_store_dirty = false;
[OUT]     }
[OUT] }
[OUT] 
[OUT] void ai_learning_reset_session(pong_game_t *g)
[OUT] {
[OUT]     if (!g) return;
[OUT]     g->ai_profile_left = ai_profile_default();
[OUT]     g->ai_profile_right = ai_profile_default();
[OUT]     ai_learning_load_store(g);
[OUT] }
[OUT] 
[OUT] void ai_learning_set_mode(pong_game_t *g, ai_learn_mode_t mode)
[OUT] {
[OUT]     if (!g) return;
[OUT]     switch (mode)
[OUT]     {
[OUT]         case kAiLearnModeBoth:
[OUT]         case kAiLearnModeAiAlgo:
[OUT]         case kAiLearnModeAlgoAi:
[OUT]             g->ai_learn_mode = mode;
[OUT] ---
[OUT] 
[OUT]     s = clampf(s, 0.70f, 2.60f);
[OUT]     return s;
[OUT] }
[OUT] 
[OUT] static float ai_lead_scale(const pong_game_t *g, bool right_side)
[OUT] {
[OUT]     if (!g) return 1.0f;
[OUT]     if (!ai_learning_side_selected(g, right_side)) return 1.0f;
[OUT]     const ai_learn_profile_t *p = ai_profile_side_const(g, right_side);
[OUT]     if (!p) return 1.0f;
[OUT]     return clampf(p->lead_scale, 0.70f, 2.00f);
[OUT] }
[OUT] 
[OUT] static void ai_update_telemetry_window(pong_game_t *g)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     if (g->ai_telemetry_start_cycles == 0u)
[OUT]     {
[OUT]         g->ai_telemetry_start_cycles = time_hal_cycles();
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     uint32_t elapsed_us = time_hal_elapsed_us(g->ai_telemetry_start_cycles);
[OUT]     if (elapsed_us < 1000000u) return;
[OUT] 
[OUT]     uint32_t npu_hz = 0u;
[OUT]     uint32_t fb_hz = 0u;
[OUT] 
[OUT]     if (elapsed_us > 0u)
[OUT]     {
[OUT]         npu_hz = (uint32_t)(((uint64_t)g->ai_npu_attempts_window * 1000000ull) / (uint64_t)elapsed_us);
[OUT]         fb_hz = (uint32_t)(((uint64_t)g->ai_fallback_window * 1000000ull) / (uint64_t)elapsed_us);
[OUT]     }
[OUT] 
[OUT]     g->ai_npu_rate_hz = clampu16(npu_hz, 999u);
[OUT]     g->ai_fallback_rate_hz = clampu16(fb_hz, 999u);
[OUT]     g->ai_npu_attempts_window = 0u;
[OUT]     g->ai_fallback_window = 0u;
[OUT]     g->ai_telemetry_start_cycles = time_hal_cycles();
[OUT] }
[OUT] 
[OUT] static void ai_step_one(pong_game_t *g, float dt, pong_paddle_t *p, bool right_side)
[OUT] {
[OUT]     if (!g || !p) return;
[OUT] 
[OUT]     bool ball_toward = right_side ? (g->ball.vx > 0.0f) : (g->ball.vx < 0.0f);
[OUT]     bool side_edgeai = ai_learning_side_selected(g, right_side);
[OUT]     bool use_npu = g->ai_enabled && side_edgeai && ball_toward;
[OUT] 
[OUT]     /* Refresh AI target at a lower rate for difficulty and lower CPU. */
[OUT]     uint32_t div = ai_update_div(g, use_npu);
[OUT]     if (div == 0u) div = 1u;
[OUT]     if ((g->frame % div) == 0u)
[OUT]     {
[OUT]         float y_hit = 0.5f;
[OUT]         float z_hit = 0.5f;
[OUT]         float t_hit = 0.0f;
[OUT]         bool used_npu = false;
[OUT] 
[OUT]         if (ball_toward)
[OUT]         {
[OUT]             if (use_npu)
[OUT]             {
[OUT]                 float feat[16];
[OUT]                 float feat2[16];
[OUT]                 ai_build_features(g, feat);
[OUT] 
[OUT]                 const float *use_feat = feat;
[OUT]                 if (!right_side)
[OUT]                 {
[OUT]                     ai_mirror_features_x(feat, feat2);
[OUT]                     use_feat = feat2;
[OUT]                 }
[OUT] 
[OUT]                 g->ai_npu_attempts_window++;
[OUT]                 npu_pred_t pred;
[OUT]                 used_npu = npu_hal_predict(&g->npu, use_feat, &pred);
[OUT]                 if (used_npu)
[OUT]                 {
[OUT]                     y_hit = pred.y_hit;
[OUT]                     z_hit = pred.z_hit;
[OUT]                     t_hit = pred.t_hit;
[OUT] 
[OUT]                     /* In mixed SKILL modes, blend NPU with analytic prediction to
[OUT]                      * keep EdgeAI competitive against fixed ALGO baseline.
[OUT]                      */
[OUT]                     if (g->ai_learn_mode != kAiLearnModeBoth)
[OUT]                     {
[OUT]                         float y_ref = 0.5f;
[OUT]                         float z_ref = 0.5f;
[OUT]                         float t_ref = 0.0f;
[OUT]                         if (right_side)
[OUT]                         {
[OUT]                             ai_predict_right(g, dt, &y_ref, &z_ref, &t_ref);
[OUT]                         }
[OUT]                         else
[OUT]                         {
[OUT]                             ai_predict_left(g, dt, &y_ref, &z_ref, &t_ref);
[OUT]                         }
[OUT] 
[OUT]                         const float npu_w = 0.38f;
[OUT]                         const float ref_w = 1.0f - npu_w;
[OUT]                         y_hit = (ref_w * y_ref) + (npu_w * y_hit);
[OUT]                         z_hit = (ref_w * z_ref) + (npu_w * z_hit);
[OUT]                         t_hit = (ref_w * t_ref) + (npu_w * t_hit);
[OUT]                     }
[OUT]                 }
[OUT]             }
[OUT] 
[OUT]             if (!used_npu)
[OUT]             {
[OUT]                 if (right_side)
[OUT]                 {
[OUT]                     ai_predict_right(g, dt, &y_hit, &z_hit, &t_hit);
[OUT]                 }
[OUT]                 else
[OUT]                 {
[OUT]                     ai_predict_left(g, dt, &y_hit, &z_hit, &t_hit);
[OUT]                 }
[OUT]             }
[OUT] 
[OUT]             /* Learned anticipation: shift target along projected travel based on side profile. */
[OUT]             {
[OUT]                 float lead = ai_lead_scale(g, right_side);
[OUT]                 float t_use = clampf(t_hit, 0.0f, 0.80f);
[OUT]                 float k = (lead - 1.0f) * 0.45f;
[OUT]                 y_hit += g->ball.vy * t_use * k;
[OUT]                 z_hit += g->ball.vz * t_use * k;
[OUT]             }
[OUT] 
[OUT]             /* Add small noise to avoid perfect play. */
[OUT]             float noise = ai_noise(g, right_side);
[OUT]             y_hit += rand_f(g, -noise, noise);
[OUT]             z_hit += rand_f(g, -noise, noise);
[OUT]         }
[OUT] 
[OUT]         if (!used_npu)
[OUT]         {
[OUT]             g->ai_fallback_window++;
[OUT]         }
[OUT] 
[OUT]         p->target_y = clampf(y_hit, 0.0f, 1.0f);
[OUT]         p->target_z = clampf(z_hit, 0.0f, 1.0f);
[OUT]     }
[OUT] 
[OUT]     /* Speed-limited movement. */
[OUT]     float prev_y = p->y;
[OUT]     float prev_z = p->z;
[OUT] 
[OUT]     float max_speed = ai_max_speed(g, right_side);
[OUT]     float max_step = max_speed * dt;
[OUT] 
[OUT]     float dy = p->target_y - p->y;
[OUT]     float dz = p->target_z - p->z;
[OUT]     dy = clampf(dy, -max_step, max_step);
[OUT]     dz = clampf(dz, -max_step, max_step);
[OUT]     p->y += dy;
[OUT]     p->z += dz;
[2026-02-25T00:27:42Z] CMD: rg -n "ai_learn_mode|kAiLearnMode|SKILL|AI/ALGO|ALGO/AI|2AI|skill" src/game src
[OUT] src/game/game.c:278:    /* Skill mode: 2AI, AI/ALGO, ALGO/AI */
[OUT] src/game/game.c:285:            ai_learn_mode_t mode =
[OUT] src/game/game.c:286:                (i == 0) ? kAiLearnModeBoth : ((i == 1) ? kAiLearnModeAiAlgo : kAiLearnModeAlgoAi);
[OUT] src/game/game.c:287:            if (g->ai_learn_mode != mode)
[OUT] src/game/game.c:388:    g->ai_learn_mode = kAiLearnModeBoth;
[OUT] src/game/render.c:622:    if ((g->ai_learn_mode == kAiLearnModeAiAlgo) && right_side) return kSideRoleAlgo;
[OUT] src/game/render.c:623:    if ((g->ai_learn_mode == kAiLearnModeAlgoAi) && !right_side) return kSideRoleAlgo;
[OUT] src/game/render.c:875:        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, EDGEAI_UI_LABEL_X, EDGEAI_UI_ROW3_Y + label_yoff, title_scale, "SKILL", c_opt_text);
[OUT] src/game/render.c:938:        /* Skill mode: 2AI, AI/ALGO (left AI), ALGO/AI (right AI). */
[OUT] src/game/render.c:946:            ai_learn_mode_t mode =
[OUT] src/game/render.c:947:                (i == 0) ? kAiLearnModeBoth : ((i == 1) ? kAiLearnModeAiAlgo : kAiLearnModeAlgoAi);
[OUT] src/game/render.c:948:            bool sel = (g->ai_learn_mode == mode);
[OUT] src/game/render.c:952:            const char *t = (i == 0) ? "2AI" : ((i == 1) ? "AI/ALGO" : "ALGO/AI");
[OUT] src/game/render.c:1103:        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "SKILL: 2AI AI/ALGO ALGO/AI", c_body);
[OUT] src/game/game.c:278:    /* Skill mode: 2AI, AI/ALGO, ALGO/AI */
[OUT] src/game/game.c:285:            ai_learn_mode_t mode =
[OUT] src/game/game.c:286:                (i == 0) ? kAiLearnModeBoth : ((i == 1) ? kAiLearnModeAiAlgo : kAiLearnModeAlgoAi);
[OUT] src/game/game.c:287:            if (g->ai_learn_mode != mode)
[OUT] src/game/game.c:388:    g->ai_learn_mode = kAiLearnModeBoth;
[OUT] src/game/ai.c:187:        if (g->ai_learn_mode == kAiLearnModeAiAlgo) return false;
[OUT] src/game/ai.c:192:    if (g->ai_learn_mode == kAiLearnModeAlgoAi) return false;
[OUT] src/game/ai.c:252:void ai_learning_set_mode(pong_game_t *g, ai_learn_mode_t mode)
[OUT] src/game/ai.c:257:        case kAiLearnModeBoth:
[OUT] src/game/ai.c:258:        case kAiLearnModeAiAlgo:
[OUT] src/game/ai.c:259:        case kAiLearnModeAlgoAi:
[OUT] src/game/ai.c:260:            g->ai_learn_mode = mode;
[OUT] src/game/ai.c:263:            g->ai_learn_mode = kAiLearnModeBoth;
[OUT] src/game/ai.c:685:                    /* In mixed SKILL modes, blend NPU with analytic prediction to
[OUT] src/game/ai.c:688:                    if (g->ai_learn_mode != kAiLearnModeBoth)
[OUT] src/game/render.c:622:    if ((g->ai_learn_mode == kAiLearnModeAiAlgo) && right_side) return kSideRoleAlgo;
[OUT] src/game/render.c:623:    if ((g->ai_learn_mode == kAiLearnModeAlgoAi) && !right_side) return kSideRoleAlgo;
[OUT] src/game/render.c:875:        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, EDGEAI_UI_LABEL_X, EDGEAI_UI_ROW3_Y + label_yoff, title_scale, "SKILL", c_opt_text);
[OUT] src/game/render.c:938:        /* Skill mode: 2AI, AI/ALGO (left AI), ALGO/AI (right AI). */
[OUT] src/game/render.c:946:            ai_learn_mode_t mode =
[OUT] src/game/render.c:947:                (i == 0) ? kAiLearnModeBoth : ((i == 1) ? kAiLearnModeAiAlgo : kAiLearnModeAlgoAi);
[OUT] src/game/render.c:948:            bool sel = (g->ai_learn_mode == mode);
[OUT] src/game/render.c:952:            const char *t = (i == 0) ? "2AI" : ((i == 1) ? "AI/ALGO" : "ALGO/AI");
[OUT] src/game/render.c:1103:        edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, s1, "SKILL: 2AI AI/ALGO ALGO/AI", c_body);
[OUT] src/game/game.h:42:    kAiLearnModeBoth = 0,
[OUT] src/game/game.h:43:    kAiLearnModeAiAlgo = 1,
[OUT] src/game/game.h:44:    kAiLearnModeAlgoAi = 2,
[OUT] src/game/game.h:45:} ai_learn_mode_t;
[OUT] src/game/game.h:108:    ai_learn_mode_t ai_learn_mode;
[OUT] src/game/ai.c:187:        if (g->ai_learn_mode == kAiLearnModeAiAlgo) return false;
[OUT] src/game/ai.c:192:    if (g->ai_learn_mode == kAiLearnModeAlgoAi) return false;
[OUT] src/game/ai.c:252:void ai_learning_set_mode(pong_game_t *g, ai_learn_mode_t mode)
[OUT] src/game/ai.c:257:        case kAiLearnModeBoth:
[OUT] src/game/ai.c:258:        case kAiLearnModeAiAlgo:
[OUT] src/game/ai.c:259:        case kAiLearnModeAlgoAi:
[OUT] src/game/ai.c:260:            g->ai_learn_mode = mode;
[OUT] src/game/ai.c:263:            g->ai_learn_mode = kAiLearnModeBoth;
[OUT] src/game/ai.c:685:                    /* In mixed SKILL modes, blend NPU with analytic prediction to
[OUT] src/game/ai.c:688:                    if (g->ai_learn_mode != kAiLearnModeBoth)
[OUT] src/game/game.h:42:    kAiLearnModeBoth = 0,
[OUT] src/game/game.h:43:    kAiLearnModeAiAlgo = 1,
[OUT] src/game/game.h:44:    kAiLearnModeAlgoAi = 2,
[OUT] src/game/game.h:45:} ai_learn_mode_t;
[OUT] src/game/game.h:108:    ai_learn_mode_t ai_learn_mode;
[OUT] src/game/ai.h:10:void ai_learning_set_mode(pong_game_t *g, ai_learn_mode_t mode);
[OUT] src/game/ai.h:10:void ai_learning_set_mode(pong_game_t *g, ai_learn_mode_t mode);
[2026-02-25T00:27:43Z] CMD: sed -n "1,260p" src/game/modes.c && sed -n "1,320p" src/game/render.c && sed -n "1,220p" src/game/input.c
[OUT] #include "game/modes.h"
[OUT] 
[OUT] game_mode_t modes_next(game_mode_t m)
[OUT] {
[OUT]     if (m == kGameModeZeroPlayer) return kGameModeSinglePlayer;
[OUT]     if (m == kGameModeSinglePlayer) return kGameModeTwoPlayer;
[OUT]     return kGameModeZeroPlayer;
[OUT] }
[OUT] ---
[OUT] #include "game/render.h"
[OUT] 
[OUT] #include <stdbool.h>
[OUT] #include <stdint.h>
[OUT] #include <stddef.h>
[OUT] 
[OUT] #include "edgeai_config.h"
[OUT] 
[OUT] #include "platform/display_hal.h"
[OUT] #include "platform/time_hal.h"
[OUT] #include "text5x7.h"
[OUT] 
[OUT] #include "game/ui_layout.h"
[OUT] 
[OUT] static uint16_t s_tile[EDGEAI_TILE_MAX_W * EDGEAI_TILE_MAX_H];
[OUT] 
[OUT] #define EDGEAI_END_PROMPT_DELAY_FRAMES 120u
[OUT] #define EDGEAI_CONFETTI_COUNT 56
[OUT] #define EDGEAI_CONFETTI_TIME_SCALE 2.30f
[OUT] #define EDGEAI_CONFETTI_MAX_T_S 4.0f
[OUT] #define EDGEAI_COUNTDOWN_STEP_US 1000000u
[OUT] #define EDGEAI_COUNTDOWN_3_US (3u * EDGEAI_COUNTDOWN_STEP_US)
[OUT] #define EDGEAI_COUNTDOWN_2_US (2u * EDGEAI_COUNTDOWN_STEP_US)
[OUT] #define EDGEAI_COUNTDOWN_1_US EDGEAI_COUNTDOWN_STEP_US
[OUT] 
[OUT] static inline float clampf(float v, float lo, float hi)
[OUT] {
[OUT]     if (v < lo) return lo;
[OUT]     if (v > hi) return hi;
[OUT]     return v;
[OUT] }
[OUT] 
[OUT] static inline float clamp01f(float v)
[OUT] {
[OUT]     return clampf(v, 0.0f, 1.0f);
[OUT] }
[OUT] 
[OUT] static inline uint8_t clamp_u8(int32_t v)
[OUT] {
[OUT]     if (v < 0) return 0u;
[OUT]     if (v > 255) return 255u;
[OUT]     return (uint8_t)v;
[OUT] }
[OUT] 
[OUT] static void text_u3(char out[3], uint32_t v)
[OUT] {
[OUT]     if (!out) return;
[OUT]     if (v > 999u) v = 999u;
[OUT]     out[0] = (char)('0' + ((v / 100u) % 10u));
[OUT]     out[1] = (char)('0' + ((v / 10u) % 10u));
[OUT]     out[2] = (char)('0' + (v % 10u));
[OUT] }
[OUT] 
[OUT] static void text_s13(char out[4], uint32_t us)
[OUT] {
[OUT]     if (!out) return;
[OUT]     /* Convert microseconds to seconds in fixed-point "0.000" format. */
[OUT]     uint32_t milli_s = (us + 500u) / 1000u;
[OUT]     if (milli_s > 9999u) milli_s = 9999u;
[OUT] 
[OUT]     out[0] = (char)('0' + ((milli_s / 1000u) % 10u));
[OUT]     out[1] = (char)('0' + ((milli_s / 100u) % 10u));
[OUT]     out[2] = (char)('0' + ((milli_s / 10u) % 10u));
[OUT]     out[3] = (char)('0' + (milli_s % 10u));
[OUT] }
[OUT] 
[OUT] static bool rect_intersects(int32_t ax0, int32_t ay0, int32_t ax1, int32_t ay1,
[OUT]                             int32_t bx0, int32_t by0, int32_t bx1, int32_t by1)
[OUT] {
[OUT]     if (ax1 < bx0 || bx1 < ax0) return false;
[OUT]     if (ay1 < by0 || by1 < ay0) return false;
[OUT]     return true;
[OUT] }
[OUT] 
[OUT] static inline uint32_t render_hash_u32(uint32_t x)
[OUT] {
[OUT]     x ^= x >> 16;
[OUT]     x *= 0x7FEB352Du;
[OUT]     x ^= x >> 15;
[OUT]     x *= 0x846CA68Bu;
[OUT]     x ^= x >> 16;
[OUT]     return x;
[OUT] }
[OUT] 
[OUT] static bool render_end_prompt_visible(const pong_game_t *g)
[OUT] {
[OUT]     if (!g) return false;
[OUT]     if (!g->match_over) return false;
[OUT]     if (g->end_prompt_dismissed) return false;
[OUT]     return ((g->frame - g->match_over_frame) >= EDGEAI_END_PROMPT_DELAY_FRAMES);
[OUT] }
[OUT] 
[OUT] static void render_countdown(uint16_t *dst, uint32_t w, uint32_t h, int32_t tile_x0, int32_t tile_y0,
[OUT]                              const pong_game_t *g)
[OUT] {
[OUT]     if (!g || !g->countdown_active) return;
[OUT] 
[OUT]     uint32_t r = g->countdown_us_left;
[OUT]     int digit = 1;
[OUT]     uint16_t c = sw_pack_rgb565_u8(30, 220, 40); /* green */
[OUT] 
[OUT]     if (r > EDGEAI_COUNTDOWN_2_US)
[OUT]     {
[OUT]         digit = 3;
[OUT]         c = sw_pack_rgb565_u8(240, 30, 30); /* red */
[OUT]     }
[OUT]     else if (r > EDGEAI_COUNTDOWN_1_US)
[OUT]     {
[OUT]         digit = 2;
[OUT]         c = sw_pack_rgb565_u8(245, 220, 40); /* yellow */
[OUT]     }
[OUT] 
[OUT]     char s[2] = {(char)('0' + digit), 0};
[OUT]     const int32_t scale = 12;
[OUT]     int32_t tw = edgeai_text5x7_width(scale, s);
[OUT]     int32_t th = 7 * scale;
[OUT]     int32_t x = (EDGEAI_LCD_W - tw) / 2;
[OUT]     int32_t y = (EDGEAI_LCD_H - th) / 2;
[OUT]     uint16_t shadow = sw_pack_rgb565_u8(8, 8, 10);
[OUT] 
[OUT]     edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x + 4, y + 4, scale, s, shadow);
[OUT]     edgeai_text5x7_draw_scaled_sw(dst, w, h, tile_x0, tile_y0, x, y, scale, s, c);
[OUT] }
[OUT] 
[OUT] static void render_project(const render_state_t *rs, float x, float y, float z, int32_t *sx, int32_t *sy, float *out_scale)
[OUT] {
[OUT]     float scale = 1.0f / (1.0f + z * rs->persp);
[OUT]     if (out_scale) *out_scale = scale;
[OUT] 
[OUT]     float dx = (x - 0.5f) * (float)rs->world_scale_x;
[OUT]     float dy = (y - 0.5f) * (float)rs->world_scale_y;
[OUT] 
[OUT]     int32_t px = rs->cx + (int32_t)(dx * scale);
[OUT]     int32_t py = rs->cy + (int32_t)(dy * scale);
[OUT]     if (sx) *sx = px;
[OUT]     if (sy) *sy = py;
[OUT] }
[OUT] 
[OUT] static void render_compute_box(render_state_t *rs)
[OUT] {
[OUT]     /* Near (z=0) corners: (0,0), (1,0), (1,1), (0,1) */
[OUT]     render_project(rs, 0.0f, 0.0f, 0.0f, &rs->near_corners[0].x, &rs->near_corners[0].y, NULL);
[OUT]     render_project(rs, 1.0f, 0.0f, 0.0f, &rs->near_corners[1].x, &rs->near_corners[1].y, NULL);
[OUT]     render_project(rs, 1.0f, 1.0f, 0.0f, &rs->near_corners[2].x, &rs->near_corners[2].y, NULL);
[OUT]     render_project(rs, 0.0f, 1.0f, 0.0f, &rs->near_corners[3].x, &rs->near_corners[3].y, NULL);
[OUT] 
[OUT]     /* Far (z=1) corners. */
[OUT]     render_project(rs, 0.0f, 0.0f, 1.0f, &rs->far_corners[0].x, &rs->far_corners[0].y, NULL);
[OUT]     render_project(rs, 1.0f, 0.0f, 1.0f, &rs->far_corners[1].x, &rs->far_corners[1].y, NULL);
[OUT]     render_project(rs, 1.0f, 1.0f, 1.0f, &rs->far_corners[2].x, &rs->far_corners[2].y, NULL);
[OUT]     render_project(rs, 0.0f, 1.0f, 1.0f, &rs->far_corners[3].x, &rs->far_corners[3].y, NULL);
[OUT] }
[OUT] 
[OUT] void render_init(render_state_t *rs)
[OUT] {
[OUT]     if (!rs) return;
[OUT] 
[OUT]     rs->cx = EDGEAI_LCD_W / 2;
[OUT]     rs->cy = EDGEAI_LCD_H / 2;
[OUT]     rs->world_scale_x = 430;
[OUT]     rs->world_scale_y = 280;
[OUT]     rs->persp = 1.20f;
[OUT] 
[OUT]     render_compute_box(rs);
[OUT] }
[OUT] 
[OUT] static void render_draw_center_dashes(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0, const render_state_t *rs)
[OUT] {
[OUT]     (void)rs;
[OUT]     const uint16_t c_dash = sw_pack_rgb565_u8(200, 201, 204);
[OUT] 
[OUT]     const float x = 0.5f;
[OUT]     const float y = 1.0f;
[OUT]     const float dash_len = 0.05f;
[OUT]     const float gap_len = 0.05f;
[OUT] 
[OUT]     float z = 0.05f;
[OUT]     for (int i = 0; i < 14; i++)
[OUT]     {
[OUT]         float z0 = z;
[OUT]         float z1 = z + dash_len;
[OUT]         if (z1 > 0.98f) z1 = 0.98f;
[OUT] 
[OUT]         int32_t ax = 0, ay = 0, bx = 0, by = 0;
[OUT]         render_project(rs, x, y, z0, &ax, &ay, NULL);
[OUT]         render_project(rs, x, y, z1, &bx, &by, NULL);
[OUT] 
[OUT]         sw_render_line(dst, w, h, x0, y0, ax, ay, bx, by, c_dash);
[OUT]         sw_render_line(dst, w, h, x0, y0, ax + 1, ay, bx + 1, by, c_dash);
[OUT] 
[OUT]         z = z1 + gap_len;
[OUT]         if (z > 0.98f) break;
[OUT]     }
[OUT] }
[OUT] 
[OUT] static void render_draw_floor_grid(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0, const render_state_t *rs)
[OUT] {
[OUT]     const uint16_t c_grid = sw_pack_rgb565_u8(24, 25, 28);
[OUT] 
[OUT]     const float y = 1.0f;
[OUT] 
[OUT]     /* Depth cross-lines. */
[OUT]     static const float z_lines[] = {0.12f, 0.24f, 0.36f, 0.48f, 0.60f, 0.72f, 0.84f, 0.96f};
[OUT]     for (size_t i = 0; i < (sizeof(z_lines) / sizeof(z_lines[0])); i++)
[OUT]     {
[OUT]         float z = z_lines[i];
[OUT]         int32_t ax = 0, ay = 0, bx = 0, by = 0;
[OUT]         render_project(rs, 0.0f, y, z, &ax, &ay, NULL);
[OUT]         render_project(rs, 1.0f, y, z, &bx, &by, NULL);
[OUT]         sw_render_line(dst, w, h, x0, y0, ax, ay, bx, by, c_grid);
[OUT]     }
[OUT] 
[OUT]     /* Perspective rails. */
[OUT]     static const float x_lines[] = {0.25f, 0.75f};
[OUT]     for (size_t i = 0; i < (sizeof(x_lines) / sizeof(x_lines[0])); i++)
[OUT]     {
[OUT]         float x = x_lines[i];
[OUT]         int32_t ax = 0, ay = 0, bx = 0, by = 0;
[OUT]         render_project(rs, x, y, 0.05f, &ax, &ay, NULL);
[OUT]         render_project(rs, x, y, 0.98f, &bx, &by, NULL);
[OUT]         sw_render_line(dst, w, h, x0, y0, ax, ay, bx, by, c_grid);
[OUT]     }
[OUT] }
[OUT] 
[OUT] static void render_bg_tile(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0, const render_state_t *rs)
[OUT] {
[OUT]     const uint16_t c_bg = sw_pack_rgb565_u8(14, 15, 16);
[OUT]     const uint16_t c_wall_dark = sw_pack_rgb565_u8(17, 18, 21);
[OUT]     const uint16_t c_wall_mid = sw_pack_rgb565_u8(27, 29, 32);
[OUT]     const uint16_t c_wall_side = sw_pack_rgb565_u8(21, 22, 25);
[OUT] 
[OUT]     sw_render_clear(dst, w, h, c_bg);
[OUT] 
[OUT]     /* Back wall. */
[OUT]     sw_render_fill_quad(dst, w, h, x0, y0,
[OUT]                         rs->far_corners[0], rs->far_corners[1], rs->far_corners[2], rs->far_corners[3],
[OUT]                         c_wall_dark);
[OUT] 
[OUT]     /* Ceiling. */
[OUT]     sw_render_fill_quad(dst, w, h, x0, y0,
[OUT]                         rs->near_corners[0], rs->near_corners[1], rs->far_corners[1], rs->far_corners[0],
[OUT]                         c_wall_dark);
[OUT] 
[OUT]     /* Side walls. */
[OUT]     sw_render_fill_quad(dst, w, h, x0, y0,
[OUT]                         rs->near_corners[0], rs->near_corners[3], rs->far_corners[3], rs->far_corners[0],
[OUT]                         c_wall_side);
[OUT]     sw_render_fill_quad(dst, w, h, x0, y0,
[OUT]                         rs->near_corners[1], rs->near_corners[2], rs->far_corners[2], rs->far_corners[1],
[OUT]                         c_wall_side);
[OUT] 
[OUT]     /* Floor. */
[OUT]     sw_render_fill_quad(dst, w, h, x0, y0,
[OUT]                         rs->near_corners[3], rs->near_corners[2], rs->far_corners[2], rs->far_corners[3],
[OUT]                         c_wall_mid);
[OUT] 
[OUT]     render_draw_floor_grid(dst, w, h, x0, y0, rs);
[OUT]     render_draw_center_dashes(dst, w, h, x0, y0, rs);
[OUT] 
[OUT]     /* Box edges: increase wall readability while keeping the monochrome style. */
[OUT]     const uint16_t c_box_edge = sw_pack_rgb565_u8(18, 19, 22);
[OUT]     const uint16_t c_box_far = sw_pack_rgb565_u8(26, 27, 31);
[OUT] 
[OUT]     /* Far frame outline. */
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->far_corners[0].x, rs->far_corners[0].y, rs->far_corners[1].x, rs->far_corners[1].y, c_box_far);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->far_corners[1].x, rs->far_corners[1].y, rs->far_corners[2].x, rs->far_corners[2].y, c_box_far);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->far_corners[2].x, rs->far_corners[2].y, rs->far_corners[3].x, rs->far_corners[3].y, c_box_far);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->far_corners[3].x, rs->far_corners[3].y, rs->far_corners[0].x, rs->far_corners[0].y, c_box_far);
[OUT] 
[OUT]     /* Connecting edges from near to far. */
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[0].x, rs->near_corners[0].y, rs->far_corners[0].x, rs->far_corners[0].y, c_box_edge);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[1].x, rs->near_corners[1].y, rs->far_corners[1].x, rs->far_corners[1].y, c_box_edge);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[2].x, rs->near_corners[2].y, rs->far_corners[2].x, rs->far_corners[2].y, c_box_edge);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[3].x, rs->near_corners[3].y, rs->far_corners[3].x, rs->far_corners[3].y, c_box_edge);
[OUT] 
[OUT]     /* Near frame outline. */
[OUT]     const uint16_t c_frame = sw_pack_rgb565_u8(10, 10, 12);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[0].x, rs->near_corners[0].y, rs->near_corners[1].x, rs->near_corners[1].y, c_frame);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[1].x, rs->near_corners[1].y, rs->near_corners[2].x, rs->near_corners[2].y, c_frame);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[2].x, rs->near_corners[2].y, rs->near_corners[3].x, rs->near_corners[3].y, c_frame);
[OUT]     sw_render_line(dst, w, h, x0, y0, rs->near_corners[3].x, rs->near_corners[3].y, rs->near_corners[0].x, rs->near_corners[0].y, c_frame);
[OUT] }
[OUT] 
[OUT] static void render_draw_paddle(uint16_t *dst, uint32_t w, uint32_t h, int32_t x0, int32_t y0,
[OUT]                                const render_state_t *rs, const pong_paddle_t *p)
[OUT] {
[OUT]     const uint16_t c_shadow = sw_pack_rgb565_u8(8, 8, 10);
[OUT]     const uint16_t c_pad = sw_pack_rgb565_u8(214, 215, 217);
[OUT]     const uint16_t c_edge_near = sw_pack_rgb565_u8(246, 247, 249);
[OUT]     const uint16_t c_edge_far = sw_pack_rgb565_u8(156, 157, 160);
[OUT]     const uint16_t c_edge_side = sw_pack_rgb565_u8(206, 207, 209);
[OUT] 
[OUT]     float hy = p->size_y * 0.5f;
[OUT]     float hz = p->size_z * 0.5f;
[OUT] 
[OUT]     float y0n = p->y - hy;
[OUT]     float y1n = p->y + hy;
[OUT]     float z0n = p->z - hz;
[OUT]     float z1n = p->z + hz;
[OUT] 
[OUT]     sw_point_t q[4];
[OUT]     render_project(rs, p->x_plane, y0n, z0n, &q[0].x, &q[0].y, NULL);
[OUT]     render_project(rs, p->x_plane, y1n, z0n, &q[1].x, &q[1].y, NULL);
[OUT]     render_project(rs, p->x_plane, y1n, z1n, &q[2].x, &q[2].y, NULL);
[OUT]     render_project(rs, p->x_plane, y0n, z1n, &q[3].x, &q[3].y, NULL);
[OUT] 
[OUT]     /* Drop shadow. */
[OUT]     sw_point_t qs[4] = {q[0], q[1], q[2], q[3]};
[OUT]     for (int i = 0; i < 4; i++)
[OUT]     {
[OUT]         qs[i].x += 2;
[OUT]         qs[i].y += 2;
[OUT]     }
[OUT]     sw_render_fill_quad(dst, w, h, x0, y0, qs[0], qs[1], qs[2], qs[3], c_shadow);
[OUT]     sw_render_fill_quad(dst, w, h, x0, y0, q[0], q[1], q[2], q[3], c_pad);
[OUT] 
[OUT]     /* Depth edges: make z extent readable at a glance. */
[OUT]     sw_render_line(dst, w, h, x0, y0, q[0].x, q[0].y, q[1].x, q[1].y, c_edge_near);
[OUT]     sw_render_line(dst, w, h, x0, y0, q[0].x + 1, q[0].y, q[1].x + 1, q[1].y, c_edge_near);
[OUT]     sw_render_line(dst, w, h, x0, y0, q[3].x, q[3].y, q[2].x, q[2].y, c_edge_far);
[OUT] ---
[OUT] #include "game/input.h"
[OUT] 
[OUT] static inline float clampf(float v, float lo, float hi)
[OUT] {
[OUT]     if (v < lo) return lo;
[OUT]     if (v > hi) return hi;
[OUT]     return v;
[OUT] }
[OUT] 
[OUT] static float input_touch_max_speed(const pong_game_t *g)
[OUT] {
[OUT]     uint8_t d = g ? g->difficulty : 2;
[OUT]     if (d < 1) d = 1;
[OUT]     if (d > 3) d = 3;
[OUT]     switch (d)
[OUT]     {
[OUT]         /* Touch should feel 1:1; use a very high slew rate so motion does not lag behind a finger drag. */
[OUT]         case 1: return 120.0f;
[OUT]         case 2: return 140.0f;
[OUT]         default: return 160.0f;
[OUT]     }
[OUT] }
[OUT] 
[OUT] static void input_move_paddle(pong_paddle_t *p, float dt, float max_speed, float alpha)
[OUT] {
[OUT]     if (!p) return;
[OUT]     if (dt <= 0.0f) return;
[OUT] 
[OUT]     float prev_y = p->y;
[OUT]     float prev_z = p->z;
[OUT] 
[OUT]     float max_step = max_speed * dt;
[OUT] 
[OUT]     float dy = p->target_y - p->y;
[OUT]     float dz = p->target_z - p->z;
[OUT]     dy = clampf(dy, -max_step, max_step);
[OUT]     dz = clampf(dz, -max_step, max_step);
[OUT] 
[OUT]     /* Light smoothing for touch/tilt jitter. */
[OUT]     p->y += dy * alpha;
[OUT]     p->z += dz * alpha;
[OUT] 
[OUT]     float hy = p->size_y * 0.5f;
[OUT]     float hz = p->size_z * 0.5f;
[OUT]     p->y = clampf(p->y, hy, 1.0f - hy);
[OUT]     p->z = clampf(p->z, hz, 1.0f - hz);
[OUT] 
[OUT]     p->vy = (p->y - prev_y) / dt;
[OUT]     p->vz = (p->z - prev_z) / dt;
[OUT] }
[OUT] 
[OUT] void input_apply(pong_game_t *g, const platform_input_t *in, float dt)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     float max_speed = 1.30f;
[OUT]     float alpha = 0.55f;
[OUT]     if (in && in->touch_active)
[OUT]     {
[OUT]         max_speed = input_touch_max_speed(g);
[OUT]         alpha = 1.0f;
[OUT]     }
[OUT] 
[OUT]     bool p1_active = in && in->p1_active;
[OUT]     float p1_y = in ? in->p1_y : 0.5f;
[OUT]     float p1_z = in ? in->p1_z : 0.5f;
[OUT] 
[OUT]     bool p2_active = in && in->p2_active;
[OUT]     float p2_y = in ? in->p2_y : 0.5f;
[OUT]     float p2_z = in ? in->p2_z : 0.5f;
[OUT] 
[OUT]     if (g->mode != kGameModeZeroPlayer)
[OUT]     {
[OUT]         if (p1_active)
[OUT]         {
[OUT]             g->paddle_l.target_y = clampf(p1_y, 0.0f, 1.0f);
[OUT]             g->paddle_l.target_z = clampf(p1_z, 0.0f, 1.0f);
[OUT]             input_move_paddle(&g->paddle_l, dt, max_speed, alpha);
[OUT]         }
[OUT]         else
[OUT]         {
[OUT]             /* No input: hold position and clear velocity to avoid stale paddle influence. */
[OUT]             g->paddle_l.vy = 0.0f;
[OUT]             g->paddle_l.vz = 0.0f;
[OUT]             g->paddle_l.target_y = g->paddle_l.y;
[OUT]             g->paddle_l.target_z = g->paddle_l.z;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     if (g->mode == kGameModeTwoPlayer && p2_active)
[OUT]     {
[OUT]         g->paddle_r.target_y = clampf(p2_y, 0.0f, 1.0f);
[OUT]         g->paddle_r.target_z = clampf(p2_z, 0.0f, 1.0f);
[OUT]         input_move_paddle(&g->paddle_r, dt, max_speed, alpha);
[OUT]     }
[OUT]     else if (g->mode == kGameModeTwoPlayer)
[OUT]     {
[OUT]         /* No input: keep position, clear velocity to avoid stale paddle influence. */
[OUT]         g->paddle_r.vy = 0.0f;
[OUT]         g->paddle_r.vz = 0.0f;
[OUT]         g->paddle_r.target_y = g->paddle_r.y;
[OUT]         g->paddle_r.target_z = g->paddle_r.z;
[OUT]     }
[OUT] }
[2026-02-25T00:27:48Z] CMD: sed -n "220,460p" src/game/game.c && sed -n "1,220p" src/game/game.c
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     const int32_t opt_y0 = (EDGEAI_UI_ROW_H - EDGEAI_UI_OPT_H) / 2;
[OUT]     const int32_t new_y0 = (EDGEAI_UI_ROW_H - EDGEAI_UI_NEW_H) / 2;
[OUT] 
[OUT]     /* Players: 0, 1, 2 */
[OUT]     for (int32_t i = 0; i < 3; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW0_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             game_mode_t new_mode = (i == 0) ? kGameModeZeroPlayer : (i == 1) ? kGameModeSinglePlayer : kGameModeTwoPlayer;
[OUT]             if (g->mode != new_mode)
[OUT]             {
[OUT]                 g->mode = new_mode;
[OUT]                 game_reset(g);
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* Difficulty: 1, 2, 3 */
[OUT]     for (int32_t i = 0; i < 3; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW1_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             uint8_t new_diff = (uint8_t)(i + 1);
[OUT]             if (new_diff < 1) new_diff = 1;
[OUT]             if (new_diff > 3) new_diff = 3;
[OUT]             if (g->difficulty != new_diff)
[OUT]             {
[OUT]                 g->difficulty = new_diff;
[OUT]                 game_reset(g);
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* AI: ON, OFF */
[OUT]     for (int32_t i = 0; i < 2; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT2_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW2_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             bool new_ai_enabled = (i == 0);
[OUT]             if (g->ai_enabled != new_ai_enabled)
[OUT]             {
[OUT]                 g->ai_enabled = new_ai_enabled;
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* Skill mode: 2AI, AI/ALGO, ALGO/AI */
[OUT]     for (int32_t i = 0; i < 3; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW3_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             ai_learn_mode_t mode =
[OUT]                 (i == 0) ? kAiLearnModeBoth : ((i == 1) ? kAiLearnModeAiAlgo : kAiLearnModeAlgoAi);
[OUT]             if (g->ai_learn_mode != mode)
[OUT]             {
[OUT]                 ai_learning_set_mode(g, mode);
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* Persistent learning: ON, OFF */
[OUT]     for (int32_t i = 0; i < 2; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT2_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW4_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             bool en = (i == 0);
[OUT]             if (g->persistent_learning != en)
[OUT]             {
[OUT]                 ai_learning_set_persistent(g, en);
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* Perpetual play: 11, INF */
[OUT]     for (int32_t i = 0; i < 2; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT2_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW5_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             bool inf = (i == 1);
[OUT]             if (g->perpetual_play != inf)
[OUT]             {
[OUT]                 g->perpetual_play = inf;
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* Target guide: ON, OFF */
[OUT]     for (int32_t i = 0; i < 2; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT2_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW6_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             bool en = (i == 0);
[OUT]             if (g->target_overlay_enabled != en)
[OUT]             {
[OUT]                 g->target_overlay_enabled = en;
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* SPEED++: ON, OFF */
[OUT]     for (int32_t i = 0; i < 2; i++)
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_OPT2_BLOCK_X + i * (EDGEAI_UI_OPT_W + EDGEAI_UI_OPT_GAP);
[OUT]         int32_t by = EDGEAI_UI_ROW7_Y + opt_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_OPT_W, EDGEAI_UI_OPT_H))
[OUT]         {
[OUT]             bool en = (i == 0);
[OUT]             if (g->speedpp_enabled != en)
[OUT]             {
[OUT]                 g->speedpp_enabled = en;
[OUT]                 g->speedpp_stage = 0u;
[OUT]                 g->speedpp_next_threshold = 11u;
[OUT]                 g->speedpp_serve_speed_target = 0.0f;
[OUT]                 g->speedpp_peak_speed = 0.0f;
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* New game. */
[OUT]     {
[OUT]         int32_t bx = EDGEAI_UI_NEW_X;
[OUT]         int32_t by = EDGEAI_UI_ROW8_Y + new_y0;
[OUT]         if (hit_rect(px, py, bx, by, EDGEAI_UI_NEW_W, EDGEAI_UI_NEW_H))
[OUT]         {
[OUT]             game_reset(g);
[OUT]             g->menu_open = false;
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] }
[OUT] 
[OUT] void game_init(pong_game_t *g)
[OUT] {
[OUT]     if (!g) return;
[OUT]     memset(g, 0, sizeof(*g));
[OUT] 
[OUT]     g->mode = kGameModeZeroPlayer;
[OUT]     g->difficulty = 2;
[OUT]     g->ai_enabled = true;
[OUT]     g->perpetual_play = false;
[OUT]     g->persistent_learning = true;
[OUT]     g->speedpp_enabled = false;
[OUT]     g->target_overlay_enabled = true;
[OUT]     g->ai_learn_mode = kAiLearnModeBoth;
[OUT]     g->menu_open = false;
[OUT]     g->help_open = false;
[OUT]     g->ui_block_touch = false;
[OUT]     g->match_over = false;
[OUT]     g->winner_left = false;
[OUT]     g->end_prompt_dismissed = false;
[OUT]     g->countdown_active = false;
[OUT] 
[OUT]     g->rng = 1u;
[OUT]     g->frame = 0;
[OUT]     g->match_over_frame = 0u;
[OUT]     g->match_over_start_cycles = 0u;
[OUT]     g->countdown_us_left = 0u;
[OUT]     g->countdown_start_cycles = 0u;
[OUT] 
[OUT]     g->paddle_l.x_plane = 0.06f;
[OUT]     g->paddle_r.x_plane = 0.94f;
[OUT] 
[OUT]     g->paddle_l.size_y = 0.26f;
[OUT]     g->paddle_l.size_z = 0.28f;
[OUT]     g->paddle_r.size_y = 0.26f;
[OUT]     g->paddle_r.size_z = 0.28f;
[OUT] 
[OUT]     g->paddle_l.y = 0.5f;
[OUT]     g->paddle_l.z = 0.5f;
[OUT]     g->paddle_r.y = 0.5f;
[OUT]     g->paddle_r.z = 0.5f;
[OUT] 
[OUT]     g->paddle_l.target_y = g->paddle_l.y;
[OUT]     g->paddle_l.target_z = g->paddle_l.z;
[OUT]     g->paddle_r.target_y = g->paddle_r.y;
[OUT]     g->paddle_r.target_z = g->paddle_r.z;
[OUT] 
[OUT]     g->last_hit_dy = 0.0f;
[OUT]     g->last_hit_dz = 0.0f;
[OUT]     g->serve_vx = 0.0f;
[OUT]     g->serve_vy = 0.0f;
[OUT]     g->serve_vz = 0.0f;
[OUT]     g->speedpp_peak_speed = 0.0f;
[OUT]     g->speedpp_serve_speed_target = 0.0f;
[OUT]     g->speedpp_stage = 0u;
[OUT]     g->speedpp_next_threshold = 11u;
[OUT] 
[OUT]     g->accel_active = false;
[OUT]     g->accel_ax = 0.0f;
[OUT]     g->accel_ay = 0.0f;
[OUT] 
[OUT]     g->ai_telemetry_start_cycles = 0u;
[OUT]     g->ai_npu_attempts_window = 0u;
[OUT]     g->ai_fallback_window = 0u;
[OUT]     g->ai_npu_rate_hz = 0u;
[OUT]     g->ai_fallback_rate_hz = 0u;
[OUT]     g->ai_left_active = false;
[OUT]     g->ai_right_active = false;
[OUT] 
[OUT]     ai_init(g);
[OUT]     game_reset(g);
[OUT] }
[OUT] 
[OUT] void game_reset(pong_game_t *g)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     ai_learning_sync_store(g);
[OUT] 
[OUT]     g->score.left = 0;
[OUT]     g->score.right = 0;
[OUT] 
[OUT]     g->paddle_l.y = 0.5f;
[OUT]     g->paddle_l.z = 0.5f;
[OUT]     g->paddle_r.y = 0.5f;
[OUT]     g->paddle_r.z = 0.5f;
[OUT] ---
[OUT] #include "game/game.h"
[OUT] 
[OUT] #include <string.h>
[OUT] 
[OUT] #include "edgeai_config.h"
[OUT] 
[OUT] #include "game/ai.h"
[OUT] #include "game/input.h"
[OUT] #include "game/modes.h"
[OUT] #include "game/physics.h"
[OUT] #include "game/ui_layout.h"
[OUT] #include "platform/time_hal.h"
[OUT] 
[OUT] #define EDGEAI_WIN_SCORE 11u
[OUT] #define EDGEAI_END_PROMPT_DELAY_FRAMES 120u
[OUT] #define EDGEAI_P0_DEMO_RESET_US 1300000u
[OUT] #define EDGEAI_COUNTDOWN_STEP_US 1000000u
[OUT] #define EDGEAI_COUNTDOWN_TOTAL_US (3u * EDGEAI_COUNTDOWN_STEP_US)
[OUT] 
[OUT] static inline int32_t clampi(int32_t v, int32_t lo, int32_t hi)
[OUT] {
[OUT]     if (v < lo) return lo;
[OUT]     if (v > hi) return hi;
[OUT]     return v;
[OUT] }
[OUT] 
[OUT] static inline float clampf(float v, float lo, float hi)
[OUT] {
[OUT]     if (v < lo) return lo;
[OUT]     if (v > hi) return hi;
[OUT]     return v;
[OUT] }
[OUT] 
[OUT] static inline float absf(float v)
[OUT] {
[OUT]     return (v < 0.0f) ? -v : v;
[OUT] }
[OUT] 
[OUT] static inline bool hit_rect(int32_t x, int32_t y, int32_t rx, int32_t ry, int32_t rw, int32_t rh)
[OUT] {
[OUT]     return (x >= rx) && (x < (rx + rw)) && (y >= ry) && (y < (ry + rh));
[OUT] }
[OUT] 
[OUT] static float game_deadzone(float v, float dz)
[OUT] {
[OUT]     if (dz <= 0.0f) return v;
[OUT]     if (dz >= 1.0f) return 0.0f;
[OUT]     return (absf(v) < dz) ? 0.0f : v;
[OUT] }
[OUT] 
[OUT] static bool game_end_prompt_visible(const pong_game_t *g)
[OUT] {
[OUT]     if (!g) return false;
[OUT]     if (!g->match_over) return false;
[OUT]     if (g->end_prompt_dismissed) return false;
[OUT] 
[OUT]     uint32_t elapsed = g->frame - g->match_over_frame;
[OUT]     return (elapsed >= EDGEAI_END_PROMPT_DELAY_FRAMES);
[OUT] }
[OUT] 
[OUT] static void game_start_countdown(pong_game_t *g)
[OUT] {
[OUT]     if (!g) return;
[OUT]     g->serve_vx = g->ball.vx;
[OUT]     g->serve_vy = g->ball.vy;
[OUT]     g->serve_vz = g->ball.vz;
[OUT] 
[OUT]     g->ball.vx = 0.0f;
[OUT]     g->ball.vy = 0.0f;
[OUT]     g->ball.vz = 0.0f;
[OUT] 
[OUT]     g->countdown_active = true;
[OUT]     g->countdown_us_left = EDGEAI_COUNTDOWN_TOTAL_US;
[OUT]     g->countdown_start_cycles = time_hal_cycles();
[OUT] }
[OUT] 
[OUT] static void game_update_countdown(pong_game_t *g)
[OUT] {
[OUT]     if (!g || !g->countdown_active) return;
[OUT] 
[OUT]     uint32_t elapsed_us = time_hal_elapsed_us(g->countdown_start_cycles);
[OUT]     if (elapsed_us >= EDGEAI_COUNTDOWN_TOTAL_US)
[OUT]     {
[OUT]         g->countdown_us_left = 0u;
[OUT]         g->countdown_active = false;
[OUT]         g->ball.vx = g->serve_vx;
[OUT]         g->ball.vy = g->serve_vy;
[OUT]         g->ball.vz = g->serve_vz;
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     g->countdown_us_left = EDGEAI_COUNTDOWN_TOTAL_US - elapsed_us;
[OUT] }
[OUT] 
[OUT] static void game_apply_accel_ball_nudge(pong_game_t *g, const platform_input_t *in, float dt)
[OUT] {
[OUT]     if (!g || !in) return;
[OUT]     if (dt <= 0.0f) return;
[OUT]     if (g->mode != kGameModeZeroPlayer) return;
[OUT]     if (!in->accel_active) return;
[OUT] 
[OUT]     /* Tilt affects ball vertical (y) and horizontal (z) to allow outcome nudging in AI vs AI mode. */
[OUT]     float ax = clampf(in->accel_ax, -1.0f, 1.0f);
[OUT]     float ay = clampf(in->accel_ay, -1.0f, 1.0f);
[OUT] 
[OUT]     /* Input is already deadzoned/softened in accel_proc; avoid a second deadzone here. */
[OUT]     const float dz = 0.0f;
[OUT]     ax = game_deadzone(ax, dz);
[OUT]     ay = game_deadzone(ay, dz);
[OUT] 
[OUT]     /* High gain on purpose: P0 is a "mess with the outcome" mode. */
[OUT]     const float k = 14.0f;
[OUT]     g->ball.vz += ax * k * dt;
[OUT]     g->ball.vy += ay * k * dt;
[OUT] 
[OUT]     const float vlim = 6.0f;
[OUT]     g->ball.vy = clampf(g->ball.vy, -vlim, vlim);
[OUT]     g->ball.vz = clampf(g->ball.vz, -vlim, vlim);
[OUT] }
[OUT] 
[OUT] static void ui_handle_press(pong_game_t *g, float touch_x, float touch_y)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     int32_t px = (int32_t)(touch_x * (float)(EDGEAI_LCD_W - 1) + 0.5f);
[OUT]     int32_t py = (int32_t)(touch_y * (float)(EDGEAI_LCD_H - 1) + 0.5f);
[OUT]     px = clampi(px, 0, EDGEAI_LCD_W - 1);
[OUT]     py = clampi(py, 0, EDGEAI_LCD_H - 1);
[OUT] 
[OUT]     if (g->match_over)
[OUT]     {
[OUT]         if (g->mode == kGameModeZeroPlayer) return;
[OUT] 
[OUT]         if (g->end_prompt_dismissed)
[OUT]         {
[OUT]             g->end_prompt_dismissed = false;
[OUT]             if (g->frame > EDGEAI_END_PROMPT_DELAY_FRAMES)
[OUT]             {
[OUT]                 g->match_over_frame = g->frame - EDGEAI_END_PROMPT_DELAY_FRAMES;
[OUT]             }
[OUT]             else
[OUT]             {
[OUT]                 g->match_over_frame = 0u;
[OUT]             }
[OUT]             return;
[OUT]         }
[OUT] 
[OUT]         if (game_end_prompt_visible(g))
[OUT]         {
[OUT]             if (hit_rect(px, py, EDGEAI_END_BTN_YES_X, EDGEAI_END_BTN_Y, EDGEAI_END_BTN_W, EDGEAI_END_BTN_H))
[OUT]             {
[OUT]                 game_reset(g);
[OUT]                 g->match_over = false;
[OUT]                 g->winner_left = false;
[OUT]                 g->end_prompt_dismissed = false;
[OUT]                 g->menu_open = false;
[OUT]                 g->help_open = false;
[OUT]                 return;
[OUT]             }
[OUT] 
[OUT]             if (hit_rect(px, py, EDGEAI_END_BTN_NO_X, EDGEAI_END_BTN_Y, EDGEAI_END_BTN_W, EDGEAI_END_BTN_H))
[OUT]             {
[OUT]                 g->end_prompt_dismissed = true;
[OUT]                 return;
[OUT]             }
[OUT]         }
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     const int32_t pill_x = EDGEAI_UI_PILL_X;
[OUT]     const int32_t pill_y = EDGEAI_UI_PILL_Y;
[OUT]     const int32_t pill_w = EDGEAI_UI_PILL_W;
[OUT]     const int32_t pill_h = EDGEAI_UI_PILL_H;
[OUT] 
[OUT]     const int32_t help_x = EDGEAI_UI_HELP_BTN_X;
[OUT]     const int32_t help_y = EDGEAI_UI_HELP_BTN_Y;
[OUT]     const int32_t help_w = EDGEAI_UI_HELP_BTN_W;
[OUT]     const int32_t help_h = EDGEAI_UI_HELP_BTN_H;
[OUT] 
[OUT]     if (hit_rect(px, py, help_x, help_y, help_w, help_h))
[OUT]     {
[OUT]         g->help_open = !g->help_open;
[OUT]         if (g->help_open) g->menu_open = false;
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     if (hit_rect(px, py, pill_x, pill_y, pill_w, pill_h))
[OUT]     {
[OUT]         g->menu_open = !g->menu_open;
[OUT]         if (g->menu_open) g->help_open = false;
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     if (g->help_open)
[OUT]     {
[OUT]         const int32_t panel_x = EDGEAI_UI_HELP_PANEL_X;
[OUT]         const int32_t panel_y = EDGEAI_UI_HELP_PANEL_Y;
[OUT]         const int32_t panel_w = EDGEAI_UI_HELP_PANEL_W;
[OUT]         const int32_t panel_h = EDGEAI_UI_HELP_PANEL_H;
[OUT] 
[OUT]         if (!hit_rect(px, py, panel_x, panel_y, panel_w, panel_h))
[OUT]         {
[OUT]             g->help_open = false;
[OUT]             g->ui_block_touch = true;
[OUT]         }
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     if (!g->menu_open) return;
[OUT] 
[OUT]     const int32_t panel_x = EDGEAI_UI_PANEL_X;
[OUT]     const int32_t panel_y = EDGEAI_UI_PANEL_Y;
[OUT]     const int32_t panel_w = EDGEAI_UI_PANEL_W;
[OUT]     const int32_t panel_h = EDGEAI_UI_PANEL_H;
[OUT] 
[OUT]     if (!hit_rect(px, py, panel_x, panel_y, panel_w, panel_h))
[OUT]     {
[OUT]         g->menu_open = false;
[OUT]         g->ui_block_touch = true;
[OUT]         return;
[2026-02-25T00:28:00Z] CMD: sed -n "1,180p" src/game/ai.c && sed -n "760,860p" src/game/ai.c
[OUT] #include "game/ai.h"
[OUT] 
[OUT] #include <string.h>
[OUT] 
[OUT] #include "fsl_flash.h"
[OUT] #include "platform/time_hal.h"
[OUT] 
[OUT] static inline float clampf(float v, float lo, float hi)
[OUT] {
[OUT]     if (v < lo) return lo;
[OUT]     if (v > hi) return hi;
[OUT]     return v;
[OUT] }
[OUT] 
[OUT] static inline uint16_t clampu16(uint32_t v, uint16_t hi)
[OUT] {
[OUT]     if (v > (uint32_t)hi) return hi;
[OUT]     return (uint16_t)v;
[OUT] }
[OUT] 
[OUT] static inline float absf(float v)
[OUT] {
[OUT]     return (v < 0.0f) ? -v : v;
[OUT] }
[OUT] 
[OUT] static inline uint32_t xorshift32(uint32_t x)
[OUT] {
[OUT]     x ^= x << 13;
[OUT]     x ^= x >> 17;
[OUT]     x ^= x << 5;
[OUT]     return x;
[OUT] }
[OUT] 
[OUT] static float rand_f01(pong_game_t *g)
[OUT] {
[OUT]     g->rng = xorshift32(g->rng ? g->rng : 1u);
[OUT]     uint32_t u = (g->rng >> 8) & 0x00FFFFFFu;
[OUT]     return (float)u * (1.0f / 16777215.0f);
[OUT] }
[OUT] 
[OUT] static float rand_f(pong_game_t *g, float lo, float hi)
[OUT] {
[OUT]     return lo + (hi - lo) * rand_f01(g);
[OUT] }
[OUT] 
[OUT] #define EDGEAI_LEARN_STORE_MAGIC 0x4C524E31u /* "LRN1" */
[OUT] #define EDGEAI_LEARN_STORE_VERSION 0x00000002u
[OUT] #define EDGEAI_LEARN_FLASH_PROGRAM_BYTES 512u
[OUT] 
[OUT] typedef struct
[OUT] {
[OUT]     uint32_t magic;
[OUT]     uint32_t version;
[OUT]     uint32_t crc32;
[OUT]     ai_learn_profile_t left;
[OUT]     ai_learn_profile_t right;
[OUT]     uint32_t reserved[(EDGEAI_LEARN_FLASH_PROGRAM_BYTES - (3u * sizeof(uint32_t)) - (2u * sizeof(ai_learn_profile_t))) /
[OUT]                       sizeof(uint32_t)];
[OUT] } ai_learn_store_t;
[OUT] 
[OUT] static ai_learn_store_t s_learn_store = {0u};
[OUT] static bool s_learn_store_dirty = false;
[OUT] static bool s_flash_ready = false;
[OUT] static bool s_flash_init_done = false;
[OUT] static uint32_t s_flash_store_addr = 0u;
[OUT] static uint32_t s_flash_sector_size = 0u;
[OUT] static flash_config_t s_flash_cfg;
[OUT] 
[OUT] static uint32_t ai_store_checksum(const ai_learn_store_t *store)
[OUT] {
[OUT]     if (!store) return 0u;
[OUT]     ai_learn_store_t copy = *store;
[OUT]     copy.crc32 = 0u;
[OUT] 
[OUT]     const uint8_t *p = (const uint8_t *)&copy;
[OUT]     uint32_t hash = 2166136261u;
[OUT]     for (uint32_t i = 0u; i < (uint32_t)sizeof(copy); i++)
[OUT]     {
[OUT]         hash ^= p[i];
[OUT]         hash *= 16777619u;
[OUT]     }
[OUT]     return hash;
[OUT] }
[OUT] 
[OUT] static bool ai_flash_init(void)
[OUT] {
[OUT]     if (s_flash_init_done) return s_flash_ready;
[OUT]     s_flash_init_done = true;
[OUT] 
[OUT]     if (FLASH_Init(&s_flash_cfg) != kStatus_FLASH_Success) return false;
[OUT] 
[OUT]     uint32_t pflash_base = 0u;
[OUT]     uint32_t pflash_size = 0u;
[OUT]     uint32_t sector_size = 0u;
[OUT]     if (FLASH_GetProperty(&s_flash_cfg, kFLASH_PropertyPflashBlockBaseAddr, &pflash_base) != kStatus_FLASH_Success)
[OUT]         return false;
[OUT]     if (FLASH_GetProperty(&s_flash_cfg, kFLASH_PropertyPflashTotalSize, &pflash_size) != kStatus_FLASH_Success)
[OUT]         return false;
[OUT]     if (FLASH_GetProperty(&s_flash_cfg, kFLASH_PropertyPflashSectorSize, &sector_size) != kStatus_FLASH_Success)
[OUT]         return false;
[OUT]     if (sector_size < EDGEAI_LEARN_FLASH_PROGRAM_BYTES || pflash_size < sector_size) return false;
[OUT] 
[OUT]     s_flash_sector_size = sector_size;
[OUT]     s_flash_store_addr = (pflash_base + pflash_size) - sector_size;
[OUT]     s_flash_ready = true;
[OUT]     return true;
[OUT] }
[OUT] 
[OUT] static bool ai_flash_read_store(ai_learn_store_t *out_store)
[OUT] {
[OUT]     if (!out_store) return false;
[OUT]     if (!ai_flash_init()) return false;
[OUT] 
[OUT]     const ai_learn_store_t *flash_store = (const ai_learn_store_t *)(uintptr_t)s_flash_store_addr;
[OUT]     if (flash_store->magic != EDGEAI_LEARN_STORE_MAGIC) return false;
[OUT]     if (flash_store->version != EDGEAI_LEARN_STORE_VERSION) return false;
[OUT]     if (ai_store_checksum(flash_store) != flash_store->crc32) return false;
[OUT] 
[OUT]     *out_store = *flash_store;
[OUT]     return true;
[OUT] }
[OUT] 
[OUT] static bool ai_flash_write_store(const ai_learn_store_t *store)
[OUT] {
[OUT]     if (!store) return false;
[OUT]     if (!ai_flash_init()) return false;
[OUT] 
[OUT]     ai_learn_store_t write_buf;
[OUT]     memset(&write_buf, 0xFF, sizeof(write_buf));
[OUT]     write_buf = *store;
[OUT]     write_buf.crc32 = 0u;
[OUT]     write_buf.crc32 = ai_store_checksum(&write_buf);
[OUT] 
[OUT]     if (FLASH_Erase(&s_flash_cfg, s_flash_store_addr, s_flash_sector_size, kFLASH_ApiEraseKey) != kStatus_FLASH_Success)
[OUT]         return false;
[OUT]     if (FLASH_Program(&s_flash_cfg, s_flash_store_addr, (uint8_t *)&write_buf, sizeof(write_buf)) !=
[OUT]         kStatus_FLASH_Success)
[OUT]         return false;
[OUT] 
[OUT]     const ai_learn_store_t *flash_store = (const ai_learn_store_t *)(uintptr_t)s_flash_store_addr;
[OUT]     return (memcmp(flash_store, &write_buf, sizeof(write_buf)) == 0);
[OUT] }
[OUT] 
[OUT] static void ai_flash_clear_store(void)
[OUT] {
[OUT]     if (!ai_flash_init()) return;
[OUT]     (void)FLASH_Erase(&s_flash_cfg, s_flash_store_addr, s_flash_sector_size, kFLASH_ApiEraseKey);
[OUT] }
[OUT] 
[OUT] static ai_learn_profile_t ai_profile_default(void)
[OUT] {
[OUT]     ai_learn_profile_t p;
[OUT]     p.speed_scale = 1.0f;
[OUT]     p.noise_scale = 1.0f;
[OUT]     p.lead_scale = 1.0f;
[OUT]     p.hits = 0u;
[OUT]     p.misses = 0u;
[OUT]     return p;
[OUT] }
[OUT] 
[OUT] static void ai_profile_clamp(ai_learn_profile_t *p)
[OUT] {
[OUT]     if (!p) return;
[OUT]     p->speed_scale = clampf(p->speed_scale, 0.75f, 1.85f);
[OUT]     p->noise_scale = clampf(p->noise_scale, 0.40f, 2.20f);
[OUT]     p->lead_scale = clampf(p->lead_scale, 0.70f, 2.00f);
[OUT] }
[OUT] 
[OUT] static ai_learn_profile_t *ai_profile_side(pong_game_t *g, bool right_side)
[OUT] {
[OUT]     if (!g) return NULL;
[OUT]     return right_side ? &g->ai_profile_right : &g->ai_profile_left;
[OUT] }
[OUT] 
[OUT] static const ai_learn_profile_t *ai_profile_side_const(const pong_game_t *g, bool right_side)
[OUT] {
[OUT]     if (!g) return NULL;
[OUT]     return right_side ? &g->ai_profile_right : &g->ai_profile_left;
[OUT] }
[OUT] 
[OUT] ---
[OUT] 
[OUT]     /* Clamp inside arena. */
[OUT]     float hy = p->size_y * 0.5f;
[OUT]     float hz = p->size_z * 0.5f;
[OUT]     p->y = clampf(p->y, hy, 1.0f - hy);
[OUT]     p->z = clampf(p->z, hz, 1.0f - hz);
[OUT] 
[OUT]     p->vy = (p->y - prev_y) / dt;
[OUT]     p->vz = (p->z - prev_z) / dt;
[OUT] }
[OUT] 
[OUT] void ai_step(pong_game_t *g, float dt, bool ai_left, bool ai_right)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     if (ai_left)
[OUT]     {
[OUT]         ai_step_one(g, dt, &g->paddle_l, false);
[OUT]     }
[OUT]     if (ai_right)
[OUT]     {
[OUT]         ai_step_one(g, dt, &g->paddle_r, true);
[OUT]     }
[OUT] 
[OUT]     /* Gentle decay toward baseline so long sessions stay stable. */
[OUT]     if (ai_learning_side_selected(g, false))
[OUT]     {
[OUT]         ai_learn_profile_t *p = &g->ai_profile_left;
[OUT]         p->speed_scale += (1.0f - p->speed_scale) * 0.0008f;
[OUT]         p->noise_scale += (1.0f - p->noise_scale) * 0.0010f;
[OUT]         p->lead_scale += (1.0f - p->lead_scale) * 0.0008f;
[OUT]         ai_profile_clamp(p);
[OUT]     }
[OUT]     if (ai_learning_side_selected(g, true))
[OUT]     {
[OUT]         ai_learn_profile_t *p = &g->ai_profile_right;
[OUT]         p->speed_scale += (1.0f - p->speed_scale) * 0.0008f;
[OUT]         p->noise_scale += (1.0f - p->noise_scale) * 0.0010f;
[OUT]         p->lead_scale += (1.0f - p->lead_scale) * 0.0008f;
[OUT]         ai_profile_clamp(p);
[OUT]     }
[OUT] 
[OUT]     ai_update_telemetry_window(g);
[OUT] }
[2026-02-25T00:28:00Z] CMD: rg -n "ai_left_active|ai_right_active|ai_step\(|ai_enabled|mode == kGameMode" src/game/game.c src/game/ai.c && sed -n "460,760p" src/game/game.c
[OUT] src/game/ai.c:186:        if (!g->ai_right_active) return false;
[OUT] src/game/ai.c:191:    if (!g->ai_left_active) return false;
[OUT] src/game/ai.c:556:    if (g && !g->ai_enabled)
[OUT] src/game/ai.c:587:    if (g && !g->ai_enabled)
[OUT] src/game/ai.c:649:    bool use_npu = g->ai_enabled && side_edgeai && ball_toward;
[OUT] src/game/ai.c:771:void ai_step(pong_game_t *g, float dt, bool ai_left, bool ai_right)
[OUT] src/game/game.c:132:        if (g->mode == kGameModeZeroPlayer) return;
[OUT] src/game/game.c:269:            bool new_ai_enabled = (i == 0);
[OUT] src/game/game.c:270:            if (g->ai_enabled != new_ai_enabled)
[OUT] src/game/game.c:272:                g->ai_enabled = new_ai_enabled;
[OUT] src/game/game.c:383:    g->ai_enabled = true;
[OUT] src/game/game.c:441:    g->ai_left_active = false;
[OUT] src/game/game.c:442:    g->ai_right_active = false;
[OUT] src/game/game.c:493:    if (g->mode == kGameModeZeroPlayer)
[OUT] src/game/game.c:529:        if (g->mode == kGameModeZeroPlayer)
[OUT] src/game/game.c:555:    bool manual_r = (g->mode == kGameModeTwoPlayer) && in && in->p2_active;
[OUT] src/game/game.c:556:    bool ai_left = (g->mode == kGameModeZeroPlayer);
[OUT] src/game/game.c:557:    bool ai_right = (g->mode == kGameModeSinglePlayer) || (g->mode == kGameModeZeroPlayer);
[OUT] src/game/game.c:558:    if (g->mode == kGameModeTwoPlayer || manual_r) ai_right = false;
[OUT] src/game/game.c:559:    g->ai_left_active = ai_left;
[OUT] src/game/game.c:560:    g->ai_right_active = ai_right;
[OUT] src/game/game.c:561:    ai_step(g, dt, ai_left, ai_right);
[OUT] src/game/game.c:576:        g->end_prompt_dismissed = (g->mode == kGameModeZeroPlayer);
[OUT] ---
[OUT]     g->paddle_r.z = 0.5f;
[OUT] 
[OUT]     g->paddle_l.vy = 0.0f;
[OUT]     g->paddle_l.vz = 0.0f;
[OUT]     g->paddle_r.vy = 0.0f;
[OUT]     g->paddle_r.vz = 0.0f;
[OUT] 
[OUT]     g->paddle_l.target_y = g->paddle_l.y;
[OUT]     g->paddle_l.target_z = g->paddle_l.z;
[OUT]     g->paddle_r.target_y = g->paddle_r.y;
[OUT]     g->paddle_r.target_z = g->paddle_r.z;
[OUT] 
[OUT]     g->last_hit_dy = 0.0f;
[OUT]     g->last_hit_dz = 0.0f;
[OUT]     g->match_over = false;
[OUT]     g->winner_left = false;
[OUT]     g->end_prompt_dismissed = false;
[OUT]     g->match_over_frame = g->frame;
[OUT]     g->match_over_start_cycles = 0u;
[OUT]     g->ai_telemetry_start_cycles = 0u;
[OUT]     g->ai_npu_attempts_window = 0u;
[OUT]     g->ai_fallback_window = 0u;
[OUT]     g->ai_npu_rate_hz = 0u;
[OUT]     g->ai_fallback_rate_hz = 0u;
[OUT] 
[OUT]     if (g->persistent_learning)
[OUT]     {
[OUT]         ai_learning_set_persistent(g, true);
[OUT]     }
[OUT] 
[OUT]     g->rng = g->rng * 1664525u + 1013904223u;
[OUT]     int serve_dir = (g->rng & 1u) ? +1 : -1;
[OUT]     physics_reset_ball(g, serve_dir);
[OUT]     if (g->mode == kGameModeZeroPlayer)
[OUT]     {
[OUT]         g->countdown_active = false;
[OUT]         g->countdown_us_left = 0u;
[OUT]     }
[OUT]     else
[OUT]     {
[OUT]         game_start_countdown(g);
[OUT]     }
[OUT] }
[OUT] 
[OUT] void game_step(pong_game_t *g, const platform_input_t *in, float dt)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     /* Keep latest accel values in game state for UI/debug even when not used for control. */
[OUT]     g->accel_active = (in && in->accel_active);
[OUT]     g->accel_ax = in ? in->accel_ax : 0.0f;
[OUT]     g->accel_ay = in ? in->accel_ay : 0.0f;
[OUT] 
[OUT]     if (in && in->touch_pressed)
[OUT]     {
[OUT]         ui_handle_press(g, in->touch_x, in->touch_y);
[OUT]     }
[OUT] 
[OUT]     if (g->ui_block_touch)
[OUT]     {
[OUT]         if (in && in->touch_active)
[OUT]         {
[OUT]             return;
[OUT]         }
[OUT]         g->ui_block_touch = false;
[OUT]     }
[OUT] 
[OUT]     if (g->match_over)
[OUT]     {
[OUT]         if (g->mode == kGameModeZeroPlayer)
[OUT]         {
[OUT]             uint32_t elapsed_us = time_hal_elapsed_us(g->match_over_start_cycles);
[OUT]             if (elapsed_us >= EDGEAI_P0_DEMO_RESET_US)
[OUT]             {
[OUT]                 game_reset(g);
[OUT]             }
[OUT]         }
[OUT]         g->frame++;
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     if (g->menu_open || g->help_open)
[OUT]     {
[OUT]         /* Pause simulation while an overlay UI panel is open. */
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     if (in && in->mode_toggle)
[OUT]     {
[OUT]         g->mode = modes_next(g->mode);
[OUT]         game_reset(g);
[OUT]     }
[OUT] 
[OUT]     input_apply(g, in, dt);
[OUT] 
[OUT]     bool manual_r = (g->mode == kGameModeTwoPlayer) && in && in->p2_active;
[OUT]     bool ai_left = (g->mode == kGameModeZeroPlayer);
[OUT]     bool ai_right = (g->mode == kGameModeSinglePlayer) || (g->mode == kGameModeZeroPlayer);
[OUT]     if (g->mode == kGameModeTwoPlayer || manual_r) ai_right = false;
[OUT]     g->ai_left_active = ai_left;
[OUT]     g->ai_right_active = ai_right;
[OUT]     ai_step(g, dt, ai_left, ai_right);
[OUT] 
[OUT]     if (!g->countdown_active)
[OUT]     {
[OUT]         physics_step(g, dt);
[OUT]     }
[OUT]     else
[OUT]     {
[OUT]         game_update_countdown(g);
[OUT]     }
[OUT] 
[OUT]     if (!g->perpetual_play && (g->score.left >= EDGEAI_WIN_SCORE || g->score.right >= EDGEAI_WIN_SCORE))
[OUT]     {
[OUT]         g->match_over = true;
[OUT]         g->winner_left = (g->score.left >= EDGEAI_WIN_SCORE);
[OUT]         g->end_prompt_dismissed = (g->mode == kGameModeZeroPlayer);
[OUT]         g->match_over_frame = g->frame;
[OUT]         g->match_over_start_cycles = time_hal_cycles();
[OUT] 
[OUT]         g->ball.vx = 0.0f;
[OUT]         g->ball.vy = 0.0f;
[OUT]         g->ball.vz = 0.0f;
[OUT]         g->countdown_active = false;
[OUT]         g->countdown_us_left = 0u;
[OUT]     }
[OUT] 
[OUT]     /* Apply after physics so paddle hits do not overwrite the external nudge. */
[OUT]     if (!g->match_over && !g->countdown_active)
[OUT]     {
[OUT]         game_apply_accel_ball_nudge(g, in, dt);
[OUT]     }
[OUT]     g->frame++;
[OUT] }
[2026-02-25T00:28:17Z] CMD: rg -n "ai_learning_apply_result|speed_scale|noise_scale|lead_scale|hits|misses|persistent_learning|ai_learning_reset_session" src/game/ai.c src/game/physics.c src/game/game.c && sed -n "260,420p" src/game/ai.c && sed -n "1,220p" src/game/physics.c
[OUT] src/game/game.c:303:            if (g->persistent_learning != en)
[OUT] src/game/game.c:385:    g->persistent_learning = true;
[OUT] src/game/game.c:485:    if (g->persistent_learning)
[OUT] src/game/game.c:587:    /* Apply after physics so paddle hits do not overwrite the external nudge. */
[OUT] src/game/physics.c:111:static float physics_ball_speed_scale(const pong_game_t *g)
[OUT] src/game/physics.c:154:    float s = physics_ball_speed_scale(g);
[OUT] src/game/physics.c:272:    /* Touch control can produce very large paddle velocities; clamp to keep hits stable. */
[OUT] src/game/ai.c:153:    p.speed_scale = 1.0f;
[OUT] src/game/ai.c:154:    p.noise_scale = 1.0f;
[OUT] src/game/ai.c:155:    p.lead_scale = 1.0f;
[OUT] src/game/ai.c:156:    p.hits = 0u;
[OUT] src/game/ai.c:157:    p.misses = 0u;
[OUT] src/game/ai.c:164:    p->speed_scale = clampf(p->speed_scale, 0.75f, 1.85f);
[OUT] src/game/ai.c:165:    p->noise_scale = clampf(p->noise_scale, 0.40f, 2.20f);
[OUT] src/game/ai.c:166:    p->lead_scale = clampf(p->lead_scale, 0.70f, 2.00f);
[OUT] src/game/ai.c:198:    if (!g || !g->persistent_learning) return;
[OUT] src/game/ai.c:210:    if (!g || !g->persistent_learning) return;
[OUT] src/game/ai.c:244:void ai_learning_reset_session(pong_game_t *g)
[OUT] src/game/ai.c:273:        g->persistent_learning = true;
[OUT] src/game/ai.c:281:    g->persistent_learning = false;
[OUT] src/game/ai.c:282:    ai_learning_reset_session(g);
[OUT] src/game/ai.c:290:    if (!g || !g->persistent_learning) return;
[OUT] src/game/ai.c:307:    p->hits = clampu16((uint32_t)p->hits + 1u, 65535u);
[OUT] src/game/ai.c:310:    p->noise_scale *= 0.987f;
[OUT] src/game/ai.c:311:    p->speed_scale += 0.008f;
[OUT] src/game/ai.c:312:    p->lead_scale += 0.005f;
[OUT] src/game/ai.c:326:    p->misses = clampu16((uint32_t)p->misses + 1u, 65535u);
[OUT] src/game/ai.c:329:    p->noise_scale *= 0.94f;
[OUT] src/game/ai.c:330:    p->speed_scale += 0.045f;
[OUT] src/game/ai.c:331:    p->lead_scale += 0.030f;
[OUT] src/game/ai.c:447:    ai_learning_reset_session(g);
[OUT] src/game/ai.c:566:            n *= p->noise_scale;
[OUT] src/game/ai.c:597:            s *= p->speed_scale;
[OUT] src/game/ai.c:605:static float ai_lead_scale(const pong_game_t *g, bool right_side)
[OUT] src/game/ai.c:611:    return clampf(p->lead_scale, 0.70f, 2.00f);
[OUT] src/game/ai.c:725:                float lead = ai_lead_scale(g, right_side);
[OUT] src/game/ai.c:788:        p->speed_scale += (1.0f - p->speed_scale) * 0.0008f;
[OUT] src/game/ai.c:789:        p->noise_scale += (1.0f - p->noise_scale) * 0.0010f;
[OUT] src/game/ai.c:790:        p->lead_scale += (1.0f - p->lead_scale) * 0.0008f;
[OUT] src/game/ai.c:796:        p->speed_scale += (1.0f - p->speed_scale) * 0.0008f;
[OUT] src/game/ai.c:797:        p->noise_scale += (1.0f - p->noise_scale) * 0.0010f;
[OUT] src/game/ai.c:798:        p->lead_scale += (1.0f - p->lead_scale) * 0.0008f;
[OUT] ---
[OUT]             g->ai_learn_mode = mode;
[OUT]             break;
[OUT]         default:
[OUT]             g->ai_learn_mode = kAiLearnModeBoth;
[OUT]             break;
[OUT]     }
[OUT] }
[OUT] 
[OUT] void ai_learning_set_persistent(pong_game_t *g, bool enabled)
[OUT] {
[OUT]     if (!g) return;
[OUT]     if (enabled)
[OUT]     {
[OUT]         g->persistent_learning = true;
[OUT]         ai_learning_load_store(g);
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     /* Persistence OFF means no carry-over advantage:
[OUT]      * clear current learned profiles and wipe stored snapshot.
[OUT]      */
[OUT]     g->persistent_learning = false;
[OUT]     ai_learning_reset_session(g);
[OUT]     memset(&s_learn_store, 0, sizeof(s_learn_store));
[OUT]     s_learn_store_dirty = false;
[OUT]     ai_flash_clear_store();
[OUT] }
[OUT] 
[OUT] void ai_learning_sync_store(pong_game_t *g)
[OUT] {
[OUT]     if (!g || !g->persistent_learning) return;
[OUT]     if (!s_learn_store_dirty) return;
[OUT]     if (ai_flash_write_store(&s_learn_store))
[OUT]     {
[OUT]         s_learn_store_dirty = false;
[OUT]     }
[OUT] }
[OUT] 
[OUT] void ai_learning_on_paddle_hit(pong_game_t *g, bool left_side)
[OUT] {
[OUT]     if (!g) return;
[OUT]     bool right_side = !left_side;
[OUT]     if (!ai_learning_side_selected(g, right_side)) return;
[OUT] 
[OUT]     ai_learn_profile_t *p = ai_profile_side(g, right_side);
[OUT]     if (!p) return;
[OUT] 
[OUT]     p->hits = clampu16((uint32_t)p->hits + 1u, 65535u);
[OUT] 
[OUT]     /* Successful return: slightly cleaner and quicker tracking, with mild anticipation. */
[OUT]     p->noise_scale *= 0.987f;
[OUT]     p->speed_scale += 0.008f;
[OUT]     p->lead_scale += 0.005f;
[OUT]     ai_profile_clamp(p);
[OUT]     ai_learning_commit_store(g);
[OUT] }
[OUT] 
[OUT] void ai_learning_on_miss(pong_game_t *g, bool left_side)
[OUT] {
[OUT]     if (!g) return;
[OUT]     bool right_side = !left_side;
[OUT]     if (!ai_learning_side_selected(g, right_side)) return;
[OUT] 
[OUT]     ai_learn_profile_t *p = ai_profile_side(g, right_side);
[OUT]     if (!p) return;
[OUT] 
[OUT]     p->misses = clampu16((uint32_t)p->misses + 1u, 65535u);
[OUT] 
[OUT]     /* Missed return: make AI react faster and reduce wander so it recovers over the session. */
[OUT]     p->noise_scale *= 0.94f;
[OUT]     p->speed_scale += 0.045f;
[OUT]     p->lead_scale += 0.030f;
[OUT]     ai_profile_clamp(p);
[OUT]     ai_learning_commit_store(g);
[OUT] }
[OUT] 
[OUT] static void ai_sim_wall(float *p, float *v, float r)
[OUT] {
[OUT]     if (!p || !v) return;
[OUT]     if ((*p - r) < 0.0f)
[OUT]     {
[OUT]         *p = r;
[OUT]         *v = absf(*v);
[OUT]     }
[OUT]     if ((*p + r) > 1.0f)
[OUT]     {
[OUT]         *p = 1.0f - r;
[OUT]         *v = -absf(*v);
[OUT]     }
[OUT] }
[OUT] 
[OUT] static void ai_predict_right(const pong_game_t *g, float dt, float *out_y, float *out_z, float *out_t)
[OUT] {
[OUT]     if (!out_y || !out_z || !out_t)
[OUT]         return;
[OUT] 
[OUT]     *out_y = 0.5f;
[OUT]     *out_z = 0.5f;
[OUT]     *out_t = 0.0f;
[OUT]     if (!g) return;
[OUT] 
[OUT]     if (g->ball.vx <= 0.0f)
[OUT]     {
[OUT]         *out_y = 0.5f;
[OUT]         *out_z = 0.5f;
[OUT]         *out_t = 0.0f;
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     float x = g->ball.x;
[OUT]     float y = g->ball.y;
[OUT]     float z = g->ball.z;
[OUT]     float vx = g->ball.vx;
[OUT]     float vy = g->ball.vy;
[OUT]     float vz = g->ball.vz;
[OUT]     float r = g->ball.r;
[OUT] 
[OUT]     const float x_hit = g->paddle_r.x_plane - r;
[OUT]     const int max_steps = 240; /* ~4s at 60 Hz */
[OUT] 
[OUT]     for (int i = 0; i < max_steps; i++)
[OUT]     {
[OUT]         x += vx * dt;
[OUT]         y += vy * dt;
[OUT]         z += vz * dt;
[OUT]         ai_sim_wall(&y, &vy, r);
[OUT]         ai_sim_wall(&z, &vz, r);
[OUT]         if (x >= x_hit)
[OUT]         {
[OUT]             *out_y = clampf(y, 0.0f, 1.0f);
[OUT]             *out_z = clampf(z, 0.0f, 1.0f);
[OUT]             *out_t = (float)(i + 1) * dt;
[OUT]             return;
[OUT]         }
[OUT]     }
[OUT] }
[OUT] 
[OUT] static void ai_predict_left(const pong_game_t *g, float dt, float *out_y, float *out_z, float *out_t)
[OUT] {
[OUT]     if (!out_y || !out_z || !out_t)
[OUT]         return;
[OUT] 
[OUT]     *out_y = 0.5f;
[OUT]     *out_z = 0.5f;
[OUT]     *out_t = 0.0f;
[OUT]     if (!g) return;
[OUT] 
[OUT]     if (g->ball.vx >= 0.0f)
[OUT]     {
[OUT]         *out_y = 0.5f;
[OUT]         *out_z = 0.5f;
[OUT]         *out_t = 0.0f;
[OUT]         return;
[OUT]     }
[OUT] 
[OUT]     float x = g->ball.x;
[OUT]     float y = g->ball.y;
[OUT]     float z = g->ball.z;
[OUT]     float vx = g->ball.vx;
[OUT]     float vy = g->ball.vy;
[OUT]     float vz = g->ball.vz;
[OUT] ---
[OUT] #include "game/physics.h"
[OUT] 
[OUT] #include <math.h>
[OUT] #include <stddef.h>
[OUT] 
[OUT] #include "game/ai.h"
[OUT] 
[OUT] static inline float clampf(float v, float lo, float hi)
[OUT] {
[OUT]     if (v < lo) return lo;
[OUT]     if (v > hi) return hi;
[OUT]     return v;
[OUT] }
[OUT] 
[OUT] static inline float absf(float v)
[OUT] {
[OUT]     return (v < 0.0f) ? -v : v;
[OUT] }
[OUT] 
[OUT] static inline uint32_t xorshift32(uint32_t x)
[OUT] {
[OUT]     x ^= x << 13;
[OUT]     x ^= x >> 17;
[OUT]     x ^= x << 5;
[OUT]     return x;
[OUT] }
[OUT] 
[OUT] static float rand_f01(pong_game_t *g)
[OUT] {
[OUT]     g->rng = xorshift32(g->rng ? g->rng : 1u);
[OUT]     /* 24-bit mantissa fraction. */
[OUT]     uint32_t u = (g->rng >> 8) & 0x00FFFFFFu;
[OUT]     return (float)u * (1.0f / 16777215.0f);
[OUT] }
[OUT] 
[OUT] static float rand_f(pong_game_t *g, float lo, float hi)
[OUT] {
[OUT]     return lo + (hi - lo) * rand_f01(g);
[OUT] }
[OUT] 
[OUT] static float physics_ball_speed_mag(const pong_game_t *g)
[OUT] {
[OUT]     if (!g) return 0.0f;
[OUT]     float vx = g->ball.vx;
[OUT]     float vy = g->ball.vy;
[OUT]     float vz = g->ball.vz;
[OUT]     return sqrtf(vx * vx + vy * vy + vz * vz);
[OUT] }
[OUT] 
[OUT] static void physics_speedpp_track_peak(pong_game_t *g)
[OUT] {
[OUT]     if (!g) return;
[OUT]     float s = physics_ball_speed_mag(g);
[OUT]     if (s > g->speedpp_peak_speed)
[OUT]     {
[OUT]         g->speedpp_peak_speed = s;
[OUT]     }
[OUT] }
[OUT] 
[OUT] static void physics_speedpp_on_score(pong_game_t *g, bool point_to_left)
[OUT] {
[OUT]     if (!g || !g->speedpp_enabled) return;
[OUT] 
[OUT]     uint16_t scored = point_to_left ? g->score.left : g->score.right;
[OUT]     if (scored == 0u || (scored % 11u) != 0u) return;
[OUT] 
[OUT]     float base = g->speedpp_serve_speed_target;
[OUT]     if (base <= 0.0f)
[OUT]     {
[OUT]         float peak = g->speedpp_peak_speed;
[OUT]         if (peak > 0.0f)
[OUT]         {
[OUT]             base = peak;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     if (base > 0.0f)
[OUT]     {
[OUT]         g->speedpp_serve_speed_target = base * 1.05f;
[OUT]     }
[OUT] 
[OUT]     if (g->speedpp_stage < 255u)
[OUT]     {
[OUT]         g->speedpp_stage++;
[OUT]     }
[OUT] }
[OUT] 
[OUT] static int physics_substeps(const pong_game_t *g, float dt)
[OUT] {
[OUT]     if (!g) return 1;
[OUT]     if (dt <= 0.0f) return 1;
[OUT] 
[OUT]     float vmax = absf(g->ball.vx);
[OUT]     float avy = absf(g->ball.vy);
[OUT]     float avz = absf(g->ball.vz);
[OUT]     if (avy > vmax) vmax = avy;
[OUT]     if (avz > vmax) vmax = avz;
[OUT] 
[OUT]     /* Keep per-substep motion small to avoid tunneling through paddles at higher speeds. */
[OUT]     float limit = g->ball.r * 0.5f;
[OUT]     if (limit < 0.001f) limit = 0.001f;
[OUT] 
[OUT]     float ratio = (vmax * dt) / limit;
[OUT]     int n = (int)ratio;
[OUT]     if ((float)n < ratio) n++;
[OUT]     if (n < 1) n = 1;
[OUT]     if (n > 8) n = 8;
[OUT]     return n;
[OUT] }
[OUT] 
[OUT] static float physics_ball_speed_scale(const pong_game_t *g)
[OUT] {
[OUT]     uint8_t d = g ? g->difficulty : 2;
[OUT]     if (d < 1) d = 1;
[OUT]     if (d > 3) d = 3;
[OUT]     switch (d)
[OUT]     {
[OUT]         case 1: return 1.95f;
[OUT]         case 2: return 2.14f;
[OUT]         default: return 2.32f;
[OUT]     }
[OUT] }
[OUT] 
[OUT] static void physics_get_tuning(const pong_game_t *g, float *serve_speed, float *speed_up, float *vlim)
[OUT] {
[OUT]     uint8_t d = g ? g->difficulty : 2;
[OUT]     if (d < 1) d = 1;
[OUT]     if (d > 3) d = 3;
[OUT] 
[OUT]     if (serve_speed) *serve_speed = 1.00f;
[OUT]     if (speed_up) *speed_up = 1.025f;
[OUT]     if (vlim) *vlim = 2.30f;
[OUT] 
[OUT]     switch (d)
[OUT]     {
[OUT]         case 1:
[OUT]             if (serve_speed) *serve_speed = 0.82f;
[OUT]             if (speed_up) *speed_up = 1.018f;
[OUT]             if (vlim) *vlim = 1.90f;
[OUT]             break;
[OUT]         case 2:
[OUT]             if (serve_speed) *serve_speed = 1.02f;
[OUT]             if (speed_up) *speed_up = 1.025f;
[OUT]             if (vlim) *vlim = 2.30f;
[OUT]             break;
[OUT]         default:
[OUT]             if (serve_speed) *serve_speed = 1.18f;
[OUT]             if (speed_up) *speed_up = 1.035f;
[OUT]             if (vlim) *vlim = 2.80f;
[OUT]             break;
[OUT]     }
[OUT] 
[OUT]     /* Scale overall ball speeds per difficulty preset. */
[OUT]     float s = physics_ball_speed_scale(g);
[OUT]     if (serve_speed) *serve_speed *= s;
[OUT]     if (vlim) *vlim *= s;
[OUT] 
[OUT]     /* Requested: double max speed cap for every difficulty setting. */
[OUT]     if (vlim) *vlim *= 2.0f;
[OUT] }
[OUT] 
[OUT] void physics_reset_ball(pong_game_t *g, int serve_dir)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     float dir = (serve_dir >= 0) ? 1.0f : -1.0f;
[OUT] 
[OUT]     g->ball.x = 0.5f;
[OUT]     g->ball.y = rand_f(g, 0.30f, 0.70f);
[OUT]     g->ball.z = rand_f(g, 0.20f, 0.80f);
[OUT]     g->ball.r = 0.040f;
[OUT] 
[OUT]     float serve_speed = 1.0f;
[OUT]     float vlim = 1.0f;
[OUT]     physics_get_tuning(g, &serve_speed, NULL, &vlim);
[OUT]     if (g->speedpp_enabled && g->speedpp_serve_speed_target > 0.0f)
[OUT]     {
[OUT]         float max_serve = vlim * 0.95f;
[OUT]         if (max_serve < serve_speed) max_serve = serve_speed;
[OUT]         serve_speed = clampf(g->speedpp_serve_speed_target, serve_speed, max_serve);
[OUT]     }
[OUT]     g->ball.vx = dir * serve_speed;
[OUT]     g->ball.vy = rand_f(g, -0.28f, 0.28f);
[OUT]     g->ball.vz = rand_f(g, -0.22f, 0.22f);
[OUT]     physics_speedpp_track_peak(g);
[OUT] }
[OUT] 
[OUT] static void physics_wall_bounce(float *p, float *v, float r)
[OUT] {
[OUT]     if (!p || !v) return;
[OUT]     if ((*p - r) < 0.0f)
[OUT]     {
[OUT]         *p = r;
[OUT]         *v = absf(*v);
[OUT]     }
[OUT]     if ((*p + r) > 1.0f)
[OUT]     {
[OUT]         *p = 1.0f - r;
[OUT]         *v = -absf(*v);
[OUT]     }
[OUT] }
[OUT] 
[OUT] static float physics_axis_reflect(float p0, float v, float tau, float r)
[OUT] {
[OUT]     float lo = r;
[OUT]     float hi = 1.0f - r;
[OUT]     float p = p0 + v * tau;
[OUT] 
[OUT]     /* Apply a small number of reflections; with substeps, more than one is unlikely. */
[OUT]     for (int i = 0; i < 4; i++)
[OUT]     {
[OUT]         if (p < lo)
[OUT]         {
[OUT]             p = lo + (lo - p);
[OUT]             continue;
[OUT]         }
[OUT]         if (p > hi)
[OUT]         {
[OUT]             p = hi - (p - hi);
[OUT]             continue;
[2026-02-25T00:28:23Z] CMD: sed -n "480,620p" src/game/ai.c
[OUT] static void ai_mirror_features_x(const float in[16], float out[16])
[OUT] {
[OUT]     if (!in || !out) return;
[OUT] 
[OUT]     /* Keep the NPU feature view always predicting the right paddle plane:
[OUT]      * - mirror x and vx
[OUT]      * - swap left/right paddle features
[OUT]      * - flip score diff sign (left-right -> right-left)
[OUT]      */
[OUT]     memcpy(out, in, 16 * sizeof(out[0]));
[OUT] 
[OUT]     out[0] = 1.0f - in[0];   /* ball.x */
[OUT]     out[3] = -in[3];         /* ball.vx */
[OUT] 
[OUT]     /* left paddle (6..9) <-> right paddle (10..11) */
[OUT]     out[6] = in[10]; /* opp y */
[OUT]     out[7] = in[11]; /* opp z */
[OUT]     out[8] = 0.0f;
[OUT]     out[9] = 0.0f;
[OUT] 
[OUT]     out[10] = in[6]; /* self y */
[OUT]     out[11] = in[7]; /* self z */
[OUT] 
[OUT]     out[12] = -in[12];
[OUT] }
[OUT] 
[OUT] static uint32_t ai_update_div(const pong_game_t *g, bool use_npu)
[OUT] {
[OUT]     uint8_t d = g ? g->difficulty : 2;
[OUT]     if (d < 1) d = 1;
[OUT]     if (d > 3) d = 3;
[OUT] 
[OUT]     if (!use_npu)
[OUT]     {
[OUT]         switch (d)
[OUT]         {
[OUT]             case 1: return 5u;
[OUT]             case 2: return 3u;
[OUT]             default: return 2u;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     /* NPU path: throttle updates to protect frame pacing, then adapt to observed latency. */
[OUT]     uint32_t div = 4u;
[OUT]     switch (d)
[OUT]     {
[OUT]         case 1: div = 9u; break;
[OUT]         case 2: div = 7u; break;
[OUT]         default: div = 5u; break;
[OUT]     }
[OUT] 
[OUT]     uint32_t avg_us = g ? g->npu.avg_infer_us : 0u;
[OUT]     if (avg_us > 14000u) div += 3u;
[OUT]     else if (avg_us > 9000u) div += 2u;
[OUT]     else if (avg_us > 5000u) div += 1u;
[OUT] 
[OUT]     if (div < 2u) div = 2u;
[OUT]     if (div > 14u) div = 14u;
[OUT]     return div;
[OUT] }
[OUT] 
[OUT] static float ai_noise(const pong_game_t *g, bool right_side)
[OUT] {
[OUT]     uint8_t d = g ? g->difficulty : 2;
[OUT]     if (d < 1) d = 1;
[OUT]     if (d > 3) d = 3;
[OUT] 
[OUT]     float n = 0.015f;
[OUT]     switch (d)
[OUT]     {
[OUT]         case 1: n = 0.032f; break;
[OUT]         case 2: n = 0.015f; break;
[OUT]         default: n = 0.007f; break;
[OUT]     }
[OUT] 
[OUT]     /* Show clear behavior difference when NPU path is disabled. */
[OUT]     if (g && !g->ai_enabled)
[OUT]     {
[OUT]         n *= 1.7f;
[OUT]     }
[OUT] 
[OUT]     if (g && ai_learning_side_selected(g, right_side))
[OUT]     {
[OUT]         const ai_learn_profile_t *p = ai_profile_side_const(g, right_side);
[OUT]         if (p)
[OUT]         {
[OUT]             n *= p->noise_scale;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     n = clampf(n, 0.002f, 0.08f);
[OUT]     return n;
[OUT] }
[OUT] 
[OUT] static float ai_max_speed(const pong_game_t *g, bool right_side)
[OUT] {
[OUT]     uint8_t d = g ? g->difficulty : 2;
[OUT]     if (d < 1) d = 1;
[OUT]     if (d > 3) d = 3;
[OUT]     float s = 1.48f;
[OUT]     switch (d)
[OUT]     {
[OUT]         case 1: s = 1.22f; break;
[OUT]         case 2: s = 1.48f; break;
[OUT]         default: s = 1.78f; break;
[OUT]     }
[OUT] 
[OUT]     if (g && !g->ai_enabled)
[OUT]     {
[OUT]         s *= 0.82f;
[OUT]     }
[OUT] 
[OUT]     if (g && ai_learning_side_selected(g, right_side))
[OUT]     {
[OUT]         const ai_learn_profile_t *p = ai_profile_side_const(g, right_side);
[OUT]         if (p)
[OUT]         {
[OUT]             s *= p->speed_scale;
[OUT]         }
[OUT]     }
[OUT] 
[OUT]     s = clampf(s, 0.70f, 2.60f);
[OUT]     return s;
[OUT] }
[OUT] 
[OUT] static float ai_lead_scale(const pong_game_t *g, bool right_side)
[OUT] {
[OUT]     if (!g) return 1.0f;
[OUT]     if (!ai_learning_side_selected(g, right_side)) return 1.0f;
[OUT]     const ai_learn_profile_t *p = ai_profile_side_const(g, right_side);
[OUT]     if (!p) return 1.0f;
[OUT]     return clampf(p->lead_scale, 0.70f, 2.00f);
[OUT] }
[OUT] 
[OUT] static void ai_update_telemetry_window(pong_game_t *g)
[OUT] {
[OUT]     if (!g) return;
[OUT] 
[OUT]     if (g->ai_telemetry_start_cycles == 0u)
[OUT]     {
[OUT]         g->ai_telemetry_start_cycles = time_hal_cycles();
[2026-02-25T00:28:57Z] CMD: patched ai.c mixed-mode cadence + confidence gate; updated STATUS.md; git status --short; rg -n "mixed SKILL|disagreement|ai_update_div" src/game/ai.c STATUS.md
[OUT]  M STATUS.md
[OUT]  M docs/COMMAND_LOG.md
[OUT]  M src/game/ai.c
[OUT] ---
[OUT] STATUS.md:24:- Notes (mixed-mode tune): reduced EdgeAI mixed-mode handicap by using ALGO-like target update cadence plus adaptive NPU confidence gating (fallback to analytic predictor on high disagreement).
[OUT] src/game/ai.c:506:static uint32_t ai_update_div(const pong_game_t *g, bool use_npu)
[OUT] src/game/ai.c:522:    /* In mixed SKILL modes, keep EdgeAI control cadence near ALGO cadence so the
[OUT] src/game/ai.c:665:    uint32_t div = ai_update_div(g, use_npu);
[OUT] src/game/ai.c:698:                    /* In mixed SKILL modes, blend NPU with analytic prediction to
[OUT] src/game/ai.c:721:                        float disagreement = dy + dz + (0.60f * dtau);
[OUT] src/game/ai.c:724:                        if (disagreement >= 0.22f)
[OUT] src/game/ai.c:728:                        else if (disagreement > 0.0f)
[OUT] src/game/ai.c:730:                            float trust = 1.0f - (disagreement / 0.22f);
[2026-02-25T00:29:04Z] CMD: ./tools/build_frdmmcxn947.sh && ./tools/flash_frdmmcxn947.sh
[2026-02-25T00:32:41Z] RESULT: build=PASS flash=PASS
[2026-02-25T00:32:47Z] CMD: git status --short && tail -n 20 docs/COMMAND_LOG.md
[OUT]  M STATUS.md
[OUT]  M docs/COMMAND_LOG.md
[OUT]  M src/game/ai.c
[OUT] ---
[OUT] [OUT] 
[OUT] [OUT]     if (g->ai_telemetry_start_cycles == 0u)
[OUT] [OUT]     {
[OUT] [OUT]         g->ai_telemetry_start_cycles = time_hal_cycles();
[OUT] [2026-02-25T00:28:57Z] CMD: patched ai.c mixed-mode cadence + confidence gate; updated STATUS.md; git status --short; rg -n "mixed SKILL|disagreement|ai_update_div" src/game/ai.c STATUS.md
[OUT] [OUT]  M STATUS.md
[OUT] [OUT]  M docs/COMMAND_LOG.md
[OUT] [OUT]  M src/game/ai.c
[OUT] [OUT] ---
[OUT] [OUT] STATUS.md:24:- Notes (mixed-mode tune): reduced EdgeAI mixed-mode handicap by using ALGO-like target update cadence plus adaptive NPU confidence gating (fallback to analytic predictor on high disagreement).
[OUT] [OUT] src/game/ai.c:506:static uint32_t ai_update_div(const pong_game_t *g, bool use_npu)
[OUT] [OUT] src/game/ai.c:522:    /* In mixed SKILL modes, keep EdgeAI control cadence near ALGO cadence so the
[OUT] [OUT] src/game/ai.c:665:    uint32_t div = ai_update_div(g, use_npu);
[OUT] [OUT] src/game/ai.c:698:                    /* In mixed SKILL modes, blend NPU with analytic prediction to
[OUT] [OUT] src/game/ai.c:721:                        float disagreement = dy + dz + (0.60f * dtau);
[OUT] [OUT] src/game/ai.c:724:                        if (disagreement >= 0.22f)
[OUT] [OUT] src/game/ai.c:728:                        else if (disagreement > 0.0f)
[OUT] [OUT] src/game/ai.c:730:                            float trust = 1.0f - (disagreement / 0.22f);
[OUT] [2026-02-25T00:29:04Z] CMD: ./tools/build_frdmmcxn947.sh && ./tools/flash_frdmmcxn947.sh
[OUT] [2026-02-25T00:32:41Z] RESULT: build=PASS flash=PASS
[2026-02-25T00:54:39Z] CMD: git add src/game/ai.c STATUS.md docs/COMMAND_LOG.md && git commit -m "Tune mixed SKILL AI competitiveness and confidence gating" && git push origin main && git rev-parse --short HEAD
