# Set up

[First time only]
```
cd /dune/app/users/$USER
newdir=NDFD_LeptonSwapper
mkdir $newder; cd $newdir

git clone --recurse-submodules -b N2FD https://github.com/colinweber27/DUNE_ND_GeoEff.git      # Get geoEff library
cd DUNE_ND_GeoEff
# Now enter an SL7 container, if not there already
source setup.sh # Sets up compatible software products w/ UPS
cmake -DPYTHON_EXECUTABLE:FILEPATH=`which python` .
make -j geoEff # Build geoEff
make -j pyGeoEff # Build pygeoEff
```

# ND numu to FD nue event pair

It reflects the [workflow](https://indico.fnal.gov/event/62304/contributions/280309/attachments/173208/234357/Numu2nue.pdf).

```
source setup.sh

# Keeps non leptonic deposits at the earth curvature correction step and extracts lepton kinematics
python3 Edepsim_ana_nueapp_stage1.py /dune/data/users/awilkins/extrapolation/edep.LArBath.NDGenieGen.root

# Runs electron edepsim based on lepton kinematics from stage 1
# it assumes to look for the txt file in ./output/nue_output
./Electron_gen_edepsim.sh n2fd_nueapp_paired_stage1.txt

# Collate energy deposits of electron to those non-leptonic ones from stage 1
python3 Edepsim_ana_nueapp_stage2.py  n2fd_nueapp_paired_stage1.root
```
