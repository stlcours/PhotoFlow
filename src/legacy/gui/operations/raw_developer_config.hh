/* 
 */

/*

    Copyright (C) 2014 Ferrero Andrea

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.


 */

/*

    These files are distributed with PhotoFlow - http://aferrero2707.github.io/PhotoFlow/

 */

#ifndef RAW_DEVELOPER_CONFIG_DIALOG_V1_HH
#define RAW_DEVELOPER_CONFIG_DIALOG_V1_HH

#include <gtkmm.h>

#include "../../../gui/operation_config_gui.hh"
#include "../../operations/raw_developer.hh"


namespace PF {

class WBSelectorV1: public Selector
{
  std::string maker, model;
public:
  WBSelectorV1(OperationConfigGUI* dialog, std::string pname, std::string l, int val):
    Selector( dialog, pname, l, val )
  {
  }
  WBSelectorV1(OperationConfigGUI* dialog, ProcessorBase* processor, std::string pname, std::string l, int val):
    Selector( dialog, processor, pname, l, val )
  {
  }

  void set_maker_model( std::string ma, std::string mo)
  {
    bool modified = false;
    if( maker != ma || model != mo )
      modified = true;
    maker = ma; model = mo;
    if( modified ) get_value();
  }

  bool check_value( int id, const std::string& name, const std::string& val );
};



  class RawDeveloperConfigGUIV1: public OperationConfigGUI
  {
    Gtk::Notebook notebook;
    Gtk::HBox wbHBox;
    Gtk::VBox wbControlsBox;
    Gtk::VBox exposureControlsBox;
    Gtk::VBox lensControlsBox;
    Gtk::VBox demoControlsBox;
    Gtk::VBox outputControlsBox;
    Gtk::VBox hotpixelsControlsBox;
    
    WBSelectorV1 wbModeSelector;
    Slider wbTempSlider;
    Slider wbTintSlider;
    Slider wbRedSlider;
    Slider wbGreenSlider;
    Slider wbBlueSlider;
    Slider wbRedCorrSlider;
    Slider wbGreenCorrSlider;
    Slider wbBlueCorrSlider;

    Slider wb_target_L_slider;
    Slider wb_target_a_slider;
    Slider wb_target_b_slider;
    Gtk::Label wb_best_match_label;
    Gtk::HBox wbTargetBox;

		// Demosaicing method selector
		Selector demoMethodSelector;
		// False color suppression steps slider
    Slider fcsSlider;

    ExposureSlider exposureSlider;
    Slider saturationLevelSlider;
    Slider blackLevelSlider;
    Selector hlrecoModeSelector;
    Gtk::Label black_level_label;
    Gtk::Label white_level_label;
    Gtk::Alignment black_level_label_align;
    Gtk::Alignment white_level_label_align;
    Gtk::HSeparator separator;

    CheckBox hotp_enable_checkbox;
    Slider hotp_strength_slider;
    Slider hotp_threshold_slider;
    CheckBox hotp_permissive_checkbox;
    CheckBox hotp_markfixed_checkbox;
    Gtk::VBox hotp_box;
    Gtk::Frame hotp_frame;

    Selector ca_mode_selector;
    CheckBox enable_ca_checkbox;
    CheckBox auto_ca_checkbox;
    Slider ca_red_slider, ca_blue_slider;
    Gtk::VBox ca_box;
    Gtk::Frame ca_frame;

    Gtk::HBox lf_hbox1, lf_hbox2, lf_hbox3;
    Gtk::Label lf_label1, lf_label2, lf_label3;
    Gtk::Entry lf_makerEntry, lf_modelEntry, lf_lensEntry;
    CheckBox lf_enable_distortion_button, lf_enable_tca_button, lf_enable_vignetting_button, lf_enable_all_button;
    Gtk::VBox lf_box;
    Gtk::Frame lens_frame;


    Selector profileModeSelector;
    Gtk::HBox profileModeSelectorBox;

    Gtk::HBox camProfHBox;
    Gtk::VBox camProfVBox;
    Gtk::Label camProfLabel;
    Gtk::Entry camProfFileEntry;
    Gtk::Button camProfOpenButton;

    Gtk::HBox gammaModeHBox;
    Gtk::VBox gammaModeVBox;
    Selector gammaModeSelector;
    Slider inGammaLinSlider;
    Slider inGammaExpSlider;

    Selector outProfileModeSelector;
    Gtk::HBox outProfileModeSelectorBox;

    Gtk::HBox outProfHBox;
    Gtk::VBox outProfVBox;
    Gtk::Label outProfLabel;
    Gtk::Entry outProfFileEntry;
    Gtk::Button outProfOpenButton;

    double XYZ_to_CAM[3][3], CAM_to_XYZ[3][3];
    float preset_wb[3];
    
    void temp2mul(double TempK, double tint, double mul[3]);
    void mul2temp(float coeffs[3], double *TempK, double *tint);

    bool ignore_temp_tint_change;
    void temp_tint_changed();


  public:
    RawDeveloperConfigGUIV1( Layer* l );
    
    void do_update();

    void on_cam_button_open_clicked();
    void on_cam_filename_changed();
    void on_out_button_open_clicked();
    void on_out_filename_changed();

    void spot_wb( double x, double y );
    void color_spot_wb( double x, double y );
    
    //bool pointer_press_event( int button, double x, double y, int mod_key );
    bool pointer_release_event( int button, double x, double y, int mod_key );
  };

}

#endif
